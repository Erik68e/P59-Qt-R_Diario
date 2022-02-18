#include "horario.h"
#include "ui_horario.h"

Horario::Horario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Horario)
{
    ui->setupUi(this);
}

Horario::~Horario()
{
    delete ui;
}

void Horario::on_yavalio_clicked()
{
    close();
}

