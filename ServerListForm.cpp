#include "ServerListForm.h"
#include "ui_ServerListForm.h"


ServerListForm::ServerListForm(QWidget * owner, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerListForm)
{
    ui->setupUi(this);
    server = nullptr;
    connect(this, SIGNAL(closeBox()), owner, SLOT(setButtonEnabled()));
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
    connect(pClientSocket, SIGNAL(readyRead()),
            this,          SLOT(slotReadClient())
           );
    connect(pClientSocket, SIGNAL(connected()),
            pClientSocket, SLOT(sendPlayersInfo()));
}

void ServerListForm::sendPlayersInfo()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QString out;
    for(auto x : players)
        out += x + '\n';
    pClientSocket->write(out.toUtf8());
}

void ServerListForm::slotReadClient()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();

    QString in(clientSocket->read(100));
    players.insert(clientSocket, in);
}

void ServerListForm::closeEvent(QCloseEvent * event)
{
    Q_UNUSED(event);
    players.clear();
    if(serverSocket.state() == QTcpSocket::SocketState::ConnectedState)
        serverSocket.disconnectFromHost();
    for(auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->disconnectFromHost();
        delete *it;
    }
    clients.clear();

    if(server != nullptr)
        if(server->isListening())
            server->close();
    emit closeBox();
}

void ServerListForm::listenClients()
{
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
    connect(&serverSocket, SIGNAL(disconnected()),
            this, SLOT(serverDisconnected()));
    connect(&serverSocket, SIGNAL(readyRead()),
            this, SLOT(readServer()));
    serverSocket.connectToHost(ip, 32280);
    if(serverSocket.waitForConnected(3000)) {
        serverSocket.write(name.toUtf8());
    }
    else {
        emit serverSocket.disconnected();
    }

}

#include <iostream>

void ServerListForm::readServer()
{
    QStringList list;
    while (serverSocket.canReadLine())
    {
        QString data = QString(serverSocket.readLine());
        std::cout << data.toStdString() << std::endl;
        list.append(data);
    }
}

ServerListForm::~ServerListForm()
{
    players.clear();
    if(serverSocket.state() == QTcpSocket::SocketState::ConnectedState)
        serverSocket.disconnectFromHost();
    for(auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->disconnectFromHost();
        delete *it;
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
