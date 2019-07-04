#ifndef DUBAJAFORM_H
#define DUBAJAFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuBajaForm;
}

class DuBajaForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuBajaForm(const QString &nombreTabla, QWidget *parent = nullptr);
    ~DuBajaForm();
private slots:
    void on_seleccionarPushButton_clicked();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::DuBajaForm *ui;
    QString mNombreTabla;
};

#endif // DUBAJAFORM_H
