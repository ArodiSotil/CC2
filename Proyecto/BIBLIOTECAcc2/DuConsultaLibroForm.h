#ifndef DUCONSULTALIBROFORM_H
#define DUCONSULTALIBROFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuConsultaLibroForm;
}

class QSqlQueryModel;

class DuConsultaLibroForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuConsultaLibroForm(QWidget *parent = nullptr);
    ~DuConsultaLibroForm();
private:
    Ui::DuConsultaLibroForm *ui;
    QSqlQueryModel *mModel;
};

#endif // DUCONSULTALIBROFORM_H
