#ifndef LOADUNIT_H
#define LOADUNIT_H

#include <QWidget>
#include <vector>
#include "def.h"

namespace Ui {
class LoadUnit;
}

class LoadUnit : public QWidget
{
    Q_OBJECT

public:
    explicit LoadUnit(QWidget *parent = 0);
    ~LoadUnit();

    void setTable(int row,int column,LU inlu);

    void clearTable();

private:
    Ui::LoadUnit *ui;
};

#endif // LOADUNIT_H
