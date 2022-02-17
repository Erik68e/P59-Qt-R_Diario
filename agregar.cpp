#include "agregar.h"
#include "ui_agregar.h"

Agregar::Agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar)
{
    ui->setupUi(this);
}

Agregar::~Agregar()
{
    delete ui;
}

void Agregar::informacion(QString titulo, QString fecha, QString nota)
{
    this -> m_titulo = titulo;
    this -> m_fecha = fecha;
    this -> m_nota = nota;
}

void Agregar::on_btn_agregarGuardar_clicked()
{

}

void Agregar::on_salir_clicked()
{
    close();
}

const QString &Agregar::titulo() const
{
    return m_titulo;
}

void Agregar::setTitulo(const QString &newTitulo)
{
    m_titulo = newTitulo;
}

const QString &Agregar::fecha() const
{
    return m_fecha;
}

void Agregar::setFecha(const QString &newFecha)
{
    m_fecha = newFecha;
}

const QString &Agregar::nota() const
{
    return m_nota;
}

void Agregar::setNota(const QString &newNota)
{
    m_nota = newNota;
}



