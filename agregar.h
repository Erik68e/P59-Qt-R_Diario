#ifndef AGREGAR_H
#define AGREGAR_H

#include <QDialog>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDebug>

#include <diario.h>

namespace Ui {
class Agregar;
}

class Agregar : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar(QWidget *parent = nullptr);
    ~Agregar();

    QString currentDateTime();

    QString notaAgregada();
    void guardar();

private slots:
    void on_btn_agregarGuardar_clicked();

    void on_salir_clicked();

private:
    Ui::Agregar *ui;

    QString m_titulo;
    QString m_fecha;
    QString m_nota;

};

#endif // AGREGAR_H
