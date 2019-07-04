#ifndef DUMODIFICACIONFORM_H
#define DUMODIFICACIONFORM_H

#include "DuFormBase.h"

namespace Ui
{
class DuModificacionForm;
}

class QSqlTableModel;

class DuModificacionForm : public DuFormBase
{
    Q_OBJECT

public:
    explicit DuModificacionForm(const QString &nombreTabla,
                                QWidget *parent = nullptr);
    ~DuModificacionForm();
private:
    Ui::DuModificacionForm *ui;
    QSqlTableModel *mModel;
};

#endif // DUMODIFICACIONFORM_H
