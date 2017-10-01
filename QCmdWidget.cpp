#include "QCmdWidget.h"
#include <QLineEdit>

QCmdWidget::QCmdWidget(QWidget *papi) : QComboBox(papi)
{

}

/**
 * @brief QCmdWidget::setHistorial
 * Adds historial commands to combo box.
 * @param cmds Command list.
 */
void QCmdWidget::setHistorial(const QStringList &cmds)
{
	addItems(cmds);
}

/**
 * @brief QCmdWidget::getHistorial
 * To retrieve all commands typed in command.
 * @return List of commands.
 */
QStringList QCmdWidget::getHistorial() const
{
	QStringList rtn;
	for( int i = 0; i < count(); i++ )
		rtn += itemText(1);
	return rtn;
}

/**
 * @brief QCmdWidget::keyPressEvent
 * override parent function to catch enter/return key to
 * signal the command typed.
 * @param e the key event.
 */
void QCmdWidget::keyPressEvent(QKeyEvent *e)
{
	if( ((e->key() == Qt::Key_Return) || (e->key() == Qt::Key_Enter)) && !currentText().isEmpty() )
	{
		addItem(currentText());
		lineEdit()->selectAll();
		emit command(currentText());
	}
	else
		QComboBox::keyPressEvent(e);
}
