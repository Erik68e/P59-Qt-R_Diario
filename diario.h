#ifndef DIARIO_H
#define DIARIO_H

#include <QMainWindow>
#include <agregar.h>

QT_BEGIN_NAMESPACE
namespace Ui { class diario; }
QT_END_NAMESPACE

class diario : public QMainWindow
{
    Q_OBJECT

public:
    diario(QWidget *parent = nullptr);
    ~diario();

    QString currentDateTime();

private slots:
    void on_salir_clicked();

    void on_maximizar_clicked();

    void on_minimizar_clicked();

    void on_bt_Resumen_clicked();

    void on_bt_Agenda_clicked();

    void on_bt_Calendario_clicked();

    void on_bt_Horario_clicked();

    void on_bt_Informacion_clicked();

    void on_btn_agregar_clicked();

private:
    Ui::diario *ui;
};
#endif // DIARIO_H
