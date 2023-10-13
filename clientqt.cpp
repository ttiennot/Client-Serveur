#include "clientqt.h"
#include "ui_clientqt.h"

clientQT::clientQT(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clientQT)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
    QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
    QObject::connect(socket, SIGNAL(readyRead()), this, SLOT(onSocketReadyRead()));
}

clientQT::~clientQT()
{
    delete ui;
}

void clientQT::onConnectButtonClicked(){
    QString ip = ui->lineEditIP->text();
    QString port = ui->lineEditPort->text();
    bool ok;
    int portAsInt = port.toInt(&ok);
    if(ok){
        socket->connectToHost(ip, portAsInt);
    }
}

void clientQT::onSocketConnected(){
    ui->statutConnectLabel->setText("Statut connexion : connecté");
}

void clientQT::onSocketDisconnected(){
    ui->statutConnectLabel->setText("Statut connexion : déconnecté");
}

void clientQT::onSendMessageButtonClicked(){
    if(socket->state() == QTcpSocket::ConnectedState){
        socket->write("Hello server ! \n");
    }
}

void clientQT::onSocketReadyRead(){
    QByteArray data = socket->read(socket->bytesAvailable());
    QString str(data);
    ui->statutConnectLabel->setText("Statut connexion : Message recu = " + str);
}

void clientQT::onDataReceived(){
    QByteArray receivedData = socket->readAll();
    QString dataString = QString::fromUtf8(receivedData);
    ui->lineEditANSWER->setText(receivedData);
}

void clientQT::onCelciusClicked(){

}

void clientQT::onFarenheitClicked(){

}

void clientQT::onHygrometrieClicked(){

}

