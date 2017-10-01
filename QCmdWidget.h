#ifndef QCMDWIDGET_H
#define QCMDWIDGET_H

#include <QComboBox>
#include <QKeyEvent>

class QCmdWidget : public QComboBox
{
	Q_OBJECT

public:
	QCmdWidget(QWidget *papi);
	void setHistorial(const QStringList &cmds);
	QStringList getHistorial() const;

protected:
	void keyPressEvent(QKeyEvent *e);

signals:
	void command(const QString &cmd);
};

#endif // QCMDWIDGET_H
