#include "agenda.h"
#include "ui_agenda.h"

Agenda::Agenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agenda)
{
    ui->setupUi(this);
}

Agenda::~Agenda()
{
    delete ui;
}

int Agenda::getCon() const
{
    return con;
}

void Agenda::setCon(int newCon)
{
    con = newCon;
}

const QString &Agenda::titulo() const
{
    return m_titulo;
}

void Agenda::setTitulo(const QString &newTitulo)
{
    m_titulo = newTitulo;
}

const QString &Agenda::fecha() const
{
    return m_fecha;
}

void Agenda::setFecha(const QString &newFecha)
{
    m_fecha = newFecha;
}

const QString &Agenda::prioridad() const
{
    return m_prioridad;
}

void Agenda::setPrioridad(const QString &newPrioridad)
{
    m_prioridad = newPrioridad;
}

const QString &Agenda::nota() const
{
    return m_nota;
}

void Agenda::setNota(const QString &newNota)
{
    m_nota = newNota;
}

void Agenda::obtenerinformacion(QString titulo, QString fecha, QString prioridad, QString nota)
{
    setTitulo(titulo);
    setFecha(fecha);
    setPrioridad(prioridad);
    setNota(nota);
}

QString Agenda::infoAgenda()
{
    obtenerinformacion(m_titulo,m_fecha,nota(),prioridad());
    QString notaAg = " ";
            notaAg.append("\n * Actividad: " + QString::number(con) + "\n");
            notaAg.append("\n * Titulo: " + m_titulo + "\n");
            notaAg.append("\n * Fecha de evento:  " + fecha() + "\n");
            notaAg.append("\n * Prioridad:  " + m_prioridad + "\n");
            notaAg.append("\n * Nota:   " + m_nota + "\n");
            notaAg.append("__________________________________________________");
    return notaAg;
}

void Agenda::on_historial_clicked()
{
    // Abrir cuadro de dialogo para seleccionar ubicacion y nombre del archivo
    QString nombreArchivo = QFileDialog::getSaveFileName(this,
                                                         "Guardar datos",
                                                         QString(),
                                                         "Archivo de salarios (*.slr)");
    qDebug() << nombreArchivo;
    // Crear un objeto QFile
    QFile archivo(nombreArchivo);
    // Abrir para LECTURA
    if (archivo.open (QFile::ReadOnly)){
        // Crear un flujo de texto
        QTextStream entrada (&archivo);
        // Leer todo el contenido del archivo
        QString datos = " " , hasta = " " ;
        while (entrada. atEnd () == false && hasta != "->") {
            hasta = entrada.readLine();
            datos += hasta + " \n " ;
        }
        // Cargar todo el contenido a la zona del texto
        ui-> outAgenda -> clear();
        ui-> outAgenda -> setPlainText (datos);
    }
    //Cerrar archivo
    archivo.close();
}

void  Agenda::guardar()
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
    if(archivo.open(QFile::WriteOnly | QFile::Text)){
        // Crear un stream de texto
        QTextStream salida(&archivo);
        // Enviar los datos del resultado a la salida
        salida << " \t     - - Registro - - \n";
        salida << "___________________________________________________" << endl;
        salida << infoAgenda();
        salida << "\n->" << endl;
    }else{
        // Mensaje de error si no se puede abrir el archivo
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar los datos");
    }
    //Cerrar archivo
    archivo.close();
}

void Agenda::info()
{
    ui->outAgenda->appendPlainText(infoAgenda());
}

void Agenda::on_bt_guardar_clicked()
{
    guardar();
}

