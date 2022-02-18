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

void diario::informacion(QString titulo, QString fecha, QString nota, QString prioridad)
{
    titulo = ui->outTitulo->text();
    fecha = ui->outFecha_2->text();
    nota = ui->outNota->text();
    prioridad = ui->outPrioridad->text();
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
    m_titulo = ui->outTitulo->text();
    m_fecha = ui->outFecha_2->text();
    m_nota = ui->outNota->text();
    m_prioridad = ui->outPrioridad->text();
    // Crear un objeto de la ventana que queremos invocar
    Agenda *dialogo = new Agenda(this);
    dialogo->obtenerinformacion(ui->outTitulo->text(),
                                ui->outFecha_2->text(),
                                ui->outNota->text(),
                                ui->outPrioridad->text());
    dialogo->info();
    dialogo->exec();
}


void diario::on_bt_Calendario_clicked()
{
    Calendario *calen = new Calendario(this);
    calen->exec();
}


void diario::on_bt_Horario_clicked()
{
    Horario *hora = new Horario(this);
    hora->exec();
}

void diario::on_bt_Informacion_clicked()
{
    // Crear un objeto de la ventana que queremos invocar
    Informacion *info = new Informacion(this);
    info->exec();
}

void diario::on_btn_agregarGuardar_clicked()
{
    con += 1;
    m_titulo = ui->outTitulo->text();
    m_fecha = ui->outFecha_2->text();
    m_nota = ui->outNota->text();
    m_prioridad = ui->outPrioridad->text();
    ui->contador->setText(QString::number(con));

    ui->outReporte->addItem(QString::number(con) + " | " + m_titulo + " | "+ m_fecha + " | " + m_nota + " | " + m_prioridad);


    if(m_titulo == "" || m_fecha == "" || m_nota == "" || m_prioridad == ""){
        QMessageBox::warning(this,"Advertencia", "No hay informacion para agregar");
        return;
    }
    //limpiar();
}

QString diario::currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80]; tstruct = *localtime(&now);

    strftime(buf, sizeof (buf), "%Y-%m-%d | %X", &tstruct);

    return buf;
}

QString diario::notaAgregada()
{
    m_titulo = ui->outTitulo->text();
    m_fecha = ui->outFecha_2->text();
    m_nota = ui->outNota->text();
    m_prioridad = ui->outPrioridad->text();
    QString notaAg = " ";
            notaAg.append("\n * Actividad: " + QString::number(con) + "\n");
            notaAg.append("\n * Fue ingresado en esta fecha: " + currentDateTime() + "\n");
            notaAg.append("\n * Titulo: " + m_titulo + "\n");
            notaAg.append("\n * Fecha de evento:  " + m_fecha + "\n");
            notaAg.append("\n * Prioridad:  " + m_prioridad + "\n");
            notaAg.append("\n * Nota:   " + m_nota + "\n");
            notaAg.append("__________________________________________________");
    return notaAg;
}

void diario::limpiar()
{
    ui->outTitulo->setText("");
    ui->outFecha_2->setText("");
    ui->outNota->setText("");
    ui->outPrioridad->setText("");
}


void diario::on_bt_cerrarAgregado_clicked()
{
    ui->outReporte->clear();
}

