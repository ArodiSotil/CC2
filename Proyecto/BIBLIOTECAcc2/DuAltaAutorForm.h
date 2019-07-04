#ifndef DUALTAAUTORFORM_H
#define DUALTAAUTORFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuAltaAutorForm;
}

class DuAltaAutorForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuAltaAutorForm(QWidget *parent = nullptr);
    ~DuAltaAutorForm();
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::DuAltaAutorForm *ui;
};

#endif // DUALTAAUTORFORM_H
