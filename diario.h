#ifndef DIARIO_H
#define DIARIO_H

#include <QMainWindow>
#include <agenda.h>
#include <horario.h>
#include <informacion.h>
#include <calendario.h>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class diario; }
QT_END_NAMESPACE

class diario : public QMainWindow
{
    Q_OBJECT

public:
    diario(QWidget *parent = nullptr);
    ~diario();

    void informacion(QString titulo, QString fecha, QString nota, QString prioridad);

    QString currentDateTime();
    QString notaAgregada();
    void guardar();
    void limpiar();
    QList<QString> List;

private slots:
    void on_salir_clicked();

    void on_maximizar_clicked();

    void on_minimizar_clicked();

    void on_bt_Resumen_clicked();

    void on_bt_Agenda_clicked();

    void on_bt_Calendario_clicked();

    void on_bt_Horario_clicked();

    void on_bt_Informacion_clicked();

    void on_btn_agregarGuardar_clicked();

    void on_bt_cerrarAgregado_clicked();

private:
    Ui::diario *ui;

    int con = 0;
    QString m_titulo;
    QString m_fecha;
    QString m_prioridad;
    QString m_nota;
};
#endif // DIARIO_H
