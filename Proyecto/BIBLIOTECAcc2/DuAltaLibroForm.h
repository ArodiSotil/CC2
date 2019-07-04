#ifndef DUALTALIBROFORM_H
#define DUALTALIBROFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuAltaLibroForm;
}

class DuAltaLibroForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuAltaLibroForm(QWidget *parent = nullptr);
    ~DuAltaLibroForm();
    QString au;
    QString tip;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_autorSeleccionarPushButton_clicked();
    void on_editorialSeleccionarPushButton_clicked();
private:
    Ui::DuAltaLibroForm *ui;

};

#endif // DUALTALIBROFORM_H
