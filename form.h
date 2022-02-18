#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <diario.h>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    void alv();

private slots:
    void on_historial_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
