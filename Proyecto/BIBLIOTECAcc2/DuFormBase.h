#ifndef DUFORMBASE_H
#define DUFORMBASE_H

#include <QWidget>

class QMdiSubWindow;

class DuFormBase : public QWidget
{
public:
    DuFormBase(QWidget *parent = nullptr);

    void setSubWindowDriver(QMdiSubWindow *subWindowDriver)
    {
        mSubWindowDriver = subWindowDriver;
    }

    QMdiSubWindow *subWindowDriver() const
    {
        return mSubWindowDriver;
    }
private:
    QMdiSubWindow *mSubWindowDriver;
};

#endif // DUFORMBASE_H
