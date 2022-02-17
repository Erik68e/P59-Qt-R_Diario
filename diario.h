#ifndef DIARIO_H
#define DIARIO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class diario; }
QT_END_NAMESPACE

class diario : public QMainWindow
{
    Q_OBJECT

public:
    diario(QWidget *parent = nullptr);
    ~diario();

private:
    Ui::diario *ui;
};
#endif // DIARIO_H
