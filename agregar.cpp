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

QString Agregar::currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80]; tstruct = *localtime(&now);

    strftime(buf, sizeof (buf), "%Y-%m-%d | %X", &tstruct);

    return buf;
}

QString Agregar::notaAgregada()
{
    m_titulo = ui->outTitulo->text();
    m_fecha = ui->outFecha->text();
    m_nota = ui->outNota->text();
    QString notaAg = " ";
            notaAg.append("\n * Fue ingresado en esta fecha: " + currentDateTime() + "\n");
            notaAg.append("\n * Titulo: " + m_titulo + "\n");
            notaAg.append("\n * Fecha de evento:  " + m_fecha + "\n");
            notaAg.append("\n * Nota:   " + m_nota + "\n");
            notaAg.append("___________________________________________________");
    return notaAg;
}

void  Agregar::guardar()
{
    // Abrir cuadro de dialogo para seleccionar ubicacion y nombre del archivo
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar datos",
                                                         QString(),
                                                         "Archivo de salarios (*.slr)");
    qDebug() << nombreArchivo;
    // Crear un objeto QFile
    QFile archivo(nombreArchivo);
    // Abrir para escritura
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        // Crear un stream de texto
        QTextStream salida(&archivo);
        // Enviar los datos del resultado a la salida
        salida << " \t     - - Registro - - \n";
        salida << "___________________________________________________" << endl;
        salida << notaAgregada();
    }else{
        // Mensaje de error si no se puede abrir el archivo
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar los datos");
    }
    //Cerrar archivo
    archivo.close();
}

void Agregar::on_btn_agregarGuardar_clicked()
{
    ui->outEnviardatos->appendPlainText(notaAgregada());
    guardar();
}

void Agregar::on_salir_clicked()
{
    close();
}
