#ifndef AGENDA_H
#define AGENDA_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDebug>

#include <diario.h>

namespace Ui {
class Agenda;
}

class Agenda : public QDialog
{
    Q_OBJECT

public:
    explicit Agenda(QWidget *parent = nullptr);
    ~Agenda();

    void obtenerinformacion(QString titulo, QString fecha, QString prioridad, QString nota);
    QString infoAgenda();

    int getCon() const;
    void setCon(int newCon);
    const QString &titulo() const;
    void setTitulo(const QString &newTitulo);
    const QString &fecha() const;
    void setFecha(const QString &newFecha);
    const QString &prioridad() const;
    void setPrioridad(const QString &newPrioridad);
    const QString &nota() const;
    void setNota(const QString &newNota);

private slots:
    void on_historial_clicked();

private:
    Ui::Agenda *ui;

    int con = 0;
    QString m_titulo;
    QString m_fecha;
    QString m_prioridad;
    QString m_nota;
};

#endif // AGENDA_H
