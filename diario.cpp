#include "diario.h"
#include "ui_diario.h"

diario::diario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::diario)
{
    ui->setupUi(this);
    this-> setWindowFlags (Qt :: FramelessWindowHint);
    //setAttribute (Qt :: WA_TranslucentBackground, true);
    ui->outFecha->setText(currentDateTime());
}

diario::~diario()
{
    delete ui;
}

void diario::on_salir_clicked()
{
    close();
}

void diario::on_maximizar_clicked()
{
    this->setWindowState(Qt::WindowMaximized);
}

void diario::on_minimizar_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}


void diario::on_bt_Resumen_clicked()
{

}


void diario::on_bt_Agenda_clicked()
{

}


void diario::on_bt_Calendario_clicked()
{

}


void diario::on_bt_Horario_clicked()
{

}


void diario::on_bt_Informacion_clicked()
{

}

QString diario::currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80]; tstruct = *localtime(&now);

    strftime(buf, sizeof (buf), "%Y-%m-%d | %X", &tstruct);

    return buf;
}

void diario::on_btn_agregar_clicked()
{
    // Crear un objeto de la ventana que queremos invocar
    Agregar *ingresar = new Agregar(this);
    ingresar->exec();
}

