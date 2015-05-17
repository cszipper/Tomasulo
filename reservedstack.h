#ifndef RESERVEDSTACK_H
#define RESERVEDSTACK_H

#include <QWidget>
#include <vector>
#include "def.h"
//#include "station.h"

namespace Ui {
class ReservedStack;
}

class ReservedStack : public QWidget
{
    Q_OBJECT

public:
    explicit ReservedStack(QWidget *parent = 0);
    ~ReservedStack();

    void setTable(int row,int column,ReStation inrs);

    void clearTable();

private:
    Ui::ReservedStack *ui;
};



#endif // RESERVEDSTACK_H
