#ifndef INFORMACION_H
#define INFORMACION_H

#include <QDialog>
#include <diario.h>

namespace Ui {
class Informacion;
}

class Informacion : public QDialog
{
    Q_OBJECT

public:
    explicit Informacion(QWidget *parent = nullptr);
    ~Informacion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Informacion *ui;
};

#endif // INFORMACION_H
