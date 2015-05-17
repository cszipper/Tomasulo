#ifndef INSTRUCTIONSTATE_H
#define INSTRUCTIONSTATE_H

#include <QWidget>
#include <QTableWidget>
#include <vector>
#include "def.h"

namespace Ui {
class InstructionState;
}

class InstructionState : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionState(QWidget *parent = 0);
    ~InstructionState();

    void setTable(int row,int column,InStat ins);

    void clearTable();

private:
    Ui::InstructionState *ui;
};

#endif // INSTRUCTIONSTATE_H
