# QTelnet
A telnet client using Qt5 framework. Originally created for Siragga MUD client (not public).

This is a very basic telnet client, unblocking and easy to use.
Takes care of telnet protocol leaving the clean data parsing to the developer.

The telnet client only needs QTelnet.h and .cpp files and you to include in .pro
file the network library:
QT += core gui network

The rest of files/classes, QCmdWidget and QTelnetTester, where used by me to develop
it, but you can look at them to understand how to use the library.

Anyway, it is as easy as using three functions and catching other two:

### Functions
  * **`connectToHost(const QString &host, quint16 port)`**  
    To connect to a host via IP or host name
  * __`disconnectFromHost()`__  
    close connection.
  * __`sendData(const QByteArray &ba)`__  
    send data (commands, if you prefer) to the telnet server.
    This funcion requires a QByteArray in his first parameter (because you send
    bytes to server, not text. No, it's not the same: Text could be in Unicode.
    So, you need to decode your text before sending it.

### Signals
  * __`newData(const char*,int)`__  
    This is invoqued when new data comes from server.
    Beware, if you parse incoming data through code, remember that
    the text NEVER comes at once. Meaning, any text form server could
    come in an unknown number of newData calls. So, you'll need to buffer
    it until all comes. Yes, it's not easy to know if "all" has come.
    Sadly, I cannot hep you at this because it's up to the server if
    sends "prompt" or not.
  * __`stateChanged(QAbstractSocket::SocketState)`__  
    Catch this signal to know socket state changes.
