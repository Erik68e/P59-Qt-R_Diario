#include "diario.h"
#include "ui_diario.h"

diario::diario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::diario)
{
    ui->setupUi(this);
}

diario::~diario()
{
    delete ui;
}

