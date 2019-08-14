#ifndef SERVERLISTFORM_H
#define SERVERLISTFORM_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QMap>
#include <QStringListModel>

class MainWindow;


namespace Ui {
class ServerListForm;
}

class ServerListForm : public QWidget
{
    Q_OBJECT

public:
    explicit     ServerListForm (MainWindow * owner, QWidget *parent = nullptr);
                 ~ServerListForm() override;
            void connectToServer(QString ip, QString name);


public slots:
    virtual void slotNewConnection ();
            void slotReadClient    ();
            void listenClients     ();
            void serverDisconnected();
            void readServer        ();
            void popClient         ();

private:
            void closeEvent(QCloseEvent * event) override;

    QTcpServer                   * server;
    std::list<QTcpSocket*>       clients;
    QTcpSocket                   * serverSocket;
    Ui::ServerListForm           * ui;
    QMap<QTcpSocket *, QString>  players;
    QString                      myName;
    QStringListModel             model;

signals:
    void closeBox();
    void sendInfo();

};

#endif // SERVERLISTFORM_H
