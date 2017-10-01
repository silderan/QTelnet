#include "QTelnetTester.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTelnetTester w;
	w.show();

	return a.exec();
}
