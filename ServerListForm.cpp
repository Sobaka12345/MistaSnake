#include "ServerListForm.h"
#include "ui_ServerListForm.h"



ServerListForm::ServerListForm(QWidget * owner, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerListForm)
{
    ui->setupUi(this);
    server = nullptr;
    serverSocket = nullptr;
    connect(this, SIGNAL(closeBox()), owner, SLOT(setButtonEnabled()));
    ui->playerListView->setModel(&model);
}

void ServerListForm::serverDisconnected()
{
    this->close();
}

void ServerListForm::slotNewConnection()
{
    QTcpSocket* pClientSocket = server->nextPendingConnection();
    clients.push_back(pClientSocket);
    connect(pClientSocket, SIGNAL(disconnected()),
            pClientSocket, SLOT(deleteLater())
           );
    connect(pClientSocket, SIGNAL(disconnected()),
            this,          SLOT(popClient())
           );
    connect(pClientSocket, SIGNAL(readyRead()),
            this,          SLOT(slotReadClient())
           );
}

void ServerListForm::popClient()
{
    QTcpSocket * rem = (QTcpSocket*)sender();
    players.remove(rem);
    clients.remove(rem);
    QStringList list;
    for(auto x: players)
        list << x;
    model.setStringList(list);
}

void ServerListForm::slotReadClient()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();

    QString in(clientSocket->read(100));
    players.insert(clientSocket, in);


    QStringList list;
    QString str;
    for(auto x : players)
    {
        str += x + "\n";
        list << x;
    }
    model.setStringList(list);
    clientSocket->write(str.toUtf8());
    if(!clientSocket->waitForBytesWritten())
        clientSocket->disconnectFromHost();
}

void ServerListForm::closeEvent(QCloseEvent * event)
{
    Q_UNUSED(event);
    players.clear();
    if(serverSocket != nullptr)
    {
        if(serverSocket->state() == QTcpSocket::SocketState::ConnectedState)
            serverSocket->disconnectFromHost();
        serverSocket->close();
        delete serverSocket;
        serverSocket = nullptr;
    }

    clients.clear();

    if(server != nullptr)
    {
        if(server->isListening())
            server->close();
        delete server;
    }
    emit closeBox();
}

void ServerListForm::listenClients()
{
    players.insert(nullptr, myName);
    QStringList list;
    list << myName;
    model.setStringList(list);
    server = new QTcpServer(this);
    if (!server->listen(QHostAddress::Any, 32280)) {
            QMessageBox::critical(nullptr,
                                  "Server Error",
                                  "Unable to start the server:"
                                  + server->errorString()
                                 );
            server->close();
            return;
        }
        connect(server, SIGNAL(newConnection()),
                this, SLOT(slotNewConnection())
               );
}

void ServerListForm::connectToServer(QString ip, QString name)
{
    serverSocket = new  QTcpSocket();
    connect(serverSocket, SIGNAL(disconnected()),
            this, SLOT(serverDisconnected()));
    connect(serverSocket, SIGNAL(readyRead()),
            this, SLOT(readServer()));
    serverSocket->connectToHost(ip, 32280);
    serverSocket->open(QIODevice::ReadWrite);
    if(serverSocket->waitForConnected(3000)) {
        serverSocket->write(name.toUtf8());
    }
    else {
        serverSocket->disconnectFromHost();
    }

}

#include <iostream>

void ServerListForm::readServer()
{
    QStringList list;
    while(serverSocket->canReadLine())
        list.push_back(serverSocket->readLine(quint64(100)));
    model.setStringList(list);
}

ServerListForm::~ServerListForm()
{
    players.clear();

    if(serverSocket != nullptr)
    {
        if(serverSocket->state() == QTcpSocket::SocketState::ConnectedState)
            serverSocket->disconnectFromHost();
        serverSocket->close();
        delete serverSocket;
    }
    for(auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->disconnectFromHost();
    }
    clients.clear();
    if(server != nullptr)
    {
        if(server->isListening())
            server->close();
        delete server;
    }
    delete ui;
}
