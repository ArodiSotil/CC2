#ifndef DUCONSULTAFORM_H
#define DUCONSULTAFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuConsultaForm;
}

class QSqlQueryModel;

class DuConsultaForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuConsultaForm(const QString &nombreTabla,
                            QWidget *parent = nullptr);
    ~DuConsultaForm();
private:
    Ui::DuConsultaForm *ui;
    QSqlQueryModel *mModel;
};

#endif // DUCONSULTAFORM_H
