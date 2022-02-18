#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <QDialog>
#include <diario.h>

namespace Ui {
class Calendario;
}

class Calendario : public QDialog
{
    Q_OBJECT

public:
    explicit Calendario(QWidget *parent = nullptr);
    ~Calendario();

private slots:
    void on_salirCalendario_clicked();

private:
    Ui::Calendario *ui;
};

#endif // CALENDARIO_H
