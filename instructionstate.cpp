#include "instructionstate.h"
#include "ui_instructionstate.h"

InstructionState::InstructionState(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionState)
{
    ui->setupUi(this);
}

InstructionState::~InstructionState()
{
    delete ui;
}

void InstructionState::setTable(int row,int column,InStat ins){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(ins.getIns());
    ui->tableWidget->setItem(row,column,item);
    QTableWidgetItem *item2 = new QTableWidgetItem();
    item2->setText(ins.getlanchtime());
    ui->tableWidget->setItem(row,column+1,item2);
    QTableWidgetItem *item3 = new QTableWidgetItem();
    item3->setText(ins.getexectime());
    ui->tableWidget->setItem(row,column+2,item3);
    QTableWidgetItem *item4 = new QTableWidgetItem();
    item4->setText(ins.getwritetime());
    ui->tableWidget->setItem(row,column+3,item4);
}

void InstructionState::clearTable(){
    ui->tableWidget->clearContents();
}
