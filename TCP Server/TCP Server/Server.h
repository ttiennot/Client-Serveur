#pragma once
#include <qtcpserver.h>
#include <qobject.h>

class Server : public QObject
{
	Q_OBJECT

public:
	Server(QObject* parent = Q_NULLPTR);
	virtual ~Server();

private:
	QTcpServer * server;
	

public slots:

	void onServerNewConnection();
	void onClientDisconnected();
	void onClientReadyRead();
};