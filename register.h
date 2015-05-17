#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <vector>
#include "def.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

    void setTable(int row,int column,Reg inreg);

    void clearTable();

private:
    Ui::Register *ui;
};



#endif // REGISTER_H
