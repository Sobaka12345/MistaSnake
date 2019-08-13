#ifndef SERVERLISTFORM_H
#define SERVERLISTFORM_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QMap>


namespace Ui {
class ServerListForm;
}

class ServerListForm : public QWidget
{
    Q_OBJECT

public:
    explicit     ServerListForm (QWidget * owner, QWidget *parent = nullptr);
                 ~ServerListForm() override;
            void connectToServer(QString ip, QString name);


public slots:
    virtual void slotNewConnection ();
            void slotReadClient    ();
            void listenClients     ();
            void serverDisconnected();
            void readServer        ();
            void sendPlayersInfo   ();

private:
            void closeEvent(QCloseEvent * event) override;

    QTcpServer                   * server;
    std::list<QTcpSocket*>       clients;
    QTcpSocket                   serverSocket;
    Ui::ServerListForm           * ui;
    QMap<QTcpSocket *, QString>  players;

signals:
    void closeBox();

};

#endif // SERVERLISTFORM_H
