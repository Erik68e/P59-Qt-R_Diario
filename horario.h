#ifndef HORARIO_H
#define HORARIO_H

#include <QDialog>
#include <diario.h>

namespace Ui {
class Horario;
}

class Horario : public QDialog
{
    Q_OBJECT

public:
    explicit Horario(QWidget *parent = nullptr);
    ~Horario();

private slots:
    void on_yavalio_clicked();

private:
    Ui::Horario *ui;
};

#endif // HORARIO_H
