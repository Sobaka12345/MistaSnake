#include "ServerListForm.h"
#include "ui_ServerListForm.h"


ServerListForm::ServerListForm(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::ServerListForm)
{
    ui->setupUi(this);
    server = nullptr;
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

    QByteArray  arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_2);
    out << quint16(0) << "AAAAQ" ;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16));

    pClientSocket->write(arrBlock);
}


void ServerListForm::slotReadClient()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();

    char data[100];
    clientSocket->read(data, 100);
}

void ServerListForm::closeEvent(QCloseEvent * event)
{
    Q_UNUSED(event);
    for(auto it = clients.begin(); it != clients.end(); it++)
    {
        (*it)->disconnectFromHost();
        delete *it;
    }
    clients.clear();

    if(server->isListening())
        server->close();
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

ServerListForm::~ServerListForm()
{
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
