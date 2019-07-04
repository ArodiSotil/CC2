#ifndef DUSELECTORDIALOG_H
#define DUSELECTORDIALOG_H

#include <QDialog>

namespace Ui
{
class DuSelectorDialog;
}

class QSqlQueryModel;

class DuSelectorDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DuSelectorDialog(const QString &tituloDeVentana,
                              const QString &nombreTabla,
                              QWidget *parent = nullptr);
    ~DuSelectorDialog();

    int id() const
    {
        return mId;
    }
    QString descrip()const{
        return descripcion;
    }
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::DuSelectorDialog *ui;
    QSqlQueryModel *mModel;
    int mId;
    QString descripcion;
};

#endif // DUSELECTORDIALOG_H
