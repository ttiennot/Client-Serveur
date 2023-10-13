#ifndef CLIENTQT_H
#define CLIENTQT_H

#include <QMainWindow>
#include <qtcpsocket.h>


QT_BEGIN_NAMESPACE
namespace Ui { class clientQT; }
QT_END_NAMESPACE

class clientQT : public QMainWindow
{
    Q_OBJECT

public:
    clientQT(QWidget *parent = nullptr);
    ~clientQT();

private:
    Ui::clientQT *ui;
    QTcpSocket * socket;

private slots :
    void onConnectButtonClicked();
    void onSocketConnected();
    void onSocketDisconnected();
    void onSendMessageButtonClicked();
    void onSocketReadyRead();
    void onDataReceived();
    void onCelciusClicked();
    void onFarenheitClicked();
    void onHygrometrieClicked();
};
#endif // CLIENTQT_H
