#include "QTelnetTester.h"
#include "ui_QTelnetTester.h"

QTelnetTester::QTelnetTester(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::QTelnetTester),
	telnet(this)
{
	ui->setupUi(this);
	ui->leAddr->setText("10.50.0.3");
	connect( &telnet, SIGNAL(newData(const char*,int)), this, SLOT(addText(const char*,int)) );
	connect( &telnet, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onStateChanged(QAbstractSocket::SocketState)) );
	connect( ui->cbCmd, SIGNAL(command(QString)), this, SLOT(onCommand(QString)));
}

QTelnetTester::~QTelnetTester()
{
	telnet.disconnectFromHost();
	delete ui;
	ui = Q_NULLPTR;
}

void QTelnetTester::onStateChanged(QAbstractSocket::SocketState s)
{
	switch( s )
	{
	case QAbstractSocket::UnconnectedState:
		setStatusText( tr("Desconectado"), true );
		ui->btConnect->setText( tr("Conectar") );
		break;
	case QAbstractSocket::HostLookupState:
		setStatusText( tr("Resolviendo DNS %1").arg(telnet.peerName()), true );
		ui->btConnect->setText( tr("Cancelar") );
		break;
	case QAbstractSocket::ConnectingState:
		setStatusText( tr("Conectando a %1").arg(telnet.peerInfo()), true );
		ui->btConnect->setText( tr("Cancelar") );
		break;
	case QAbstractSocket::ConnectedState:
		setStatusText( tr("Conectado a %1").arg(telnet.peerInfo()), true );
		ui->btConnect->setText( tr("Desconectar") );
		break;
	case QAbstractSocket::BoundState:
		setStatusText( tr("Enlazado"), true );
		ui->btConnect->setText( tr("- - - -") );
		break;
	case QAbstractSocket::ListeningState:
		setStatusText( tr("Escuchando"), true );
		ui->btConnect->setText( tr("- - - -") );
		break;
	case QAbstractSocket::ClosingState:
		setStatusText( tr("Cerrando"), true );
		ui->btConnect->setText( tr("Forzar cierre") );
		break;

	}
}

void QTelnetTester::setStatusText(const QString &msg, bool onQTelnetTester)
{
	if( onQTelnetTester )
	{
		addText(msg.toLatin1(), msg.count());
		if( !msg.endsWith("\n") )
			addText("\n", 1);
	}
	ui->statusBar->showMessage(msg);
}

void QTelnetTester::onCommand(const QString &cmd)
{
	if( telnet.isConnected() )
	{
		telnet.sendData(cmd.toLatin1());
		telnet.sendData("\n");
	}
}

void QTelnetTester::on_btConnect_clicked()
{
	if( telnet.isConnected() )
		telnet.disconnectFromHost();
	else
		telnet.connectToHost(ui->leAddr->text(), ui->sbPort->value());
}

void QTelnetTester::addText(const char *msg, int count)
{
	ui->teOutput->insertPlainText( QByteArray(msg, count) );
}
