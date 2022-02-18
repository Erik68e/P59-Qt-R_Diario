#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::alv()
{
    ui->outAgenda->appendPlainText("Hola");
}

void Form::on_historial_clicked()
{
    alv();
}

