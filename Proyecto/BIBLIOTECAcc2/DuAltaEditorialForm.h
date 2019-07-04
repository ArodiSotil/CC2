#ifndef DUALTAEDITORIALFORM_H
#define DUALTAEDITORIALFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuAltaEditorialForm;
}

class DuAltaEditorialForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuAltaEditorialForm(QWidget *parent = nullptr);
    ~DuAltaEditorialForm();
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::DuAltaEditorialForm *ui;
};

#endif // DUALTAEDITORIALFORM_H
