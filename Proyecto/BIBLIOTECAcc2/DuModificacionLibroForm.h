#ifndef DUMODIFICACIONLIBROFORM_H
#define DUMODIFICACIONLIBROFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuModificacionLibroForm;
}

class QSqlRelationalTableModel;
class QSqlRelationalDelegate;

class DuModificacionLibroForm : public DuFormBase
{
    Q_OBJECT
public:
    explicit DuModificacionLibroForm(QWidget *parent = nullptr);
    ~DuModificacionLibroForm();
private:
    Ui::DuModificacionLibroForm *ui;
    QSqlRelationalTableModel *mModel;
    QSqlRelationalDelegate *mDelegate;
};

#endif // DUMODIFICACIONLIBROFORM_H
