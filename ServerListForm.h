#ifndef SERVERLISTFORM_H
#define SERVERLISTFORM_H

#include <QScrollArea>
#include <SFML/Network.hpp>
#include <thread>
#include <QCloseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

namespace Ui {
class ServerListForm;
}

class ServerListForm : public QScrollArea
{
    Q_OBJECT

public:
    explicit ServerListForm(QWidget *parent = nullptr);
    ~ServerListForm();


public slots:
    virtual void slotNewConnection();
    void slotReadClient   ();
    void listenClients();

private:
    QTcpServer * server;
    void ServerListForm::closeEvent(QCloseEvent * event) override;
    std::list<QTcpSocket*> clients;
    Ui::ServerListForm *ui;


};

#endif // SERVERLISTFORM_H
