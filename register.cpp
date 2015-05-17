#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::setTable(int row,int column,Reg inreg){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(inreg.getqi());
    ui->tableWidget->setItem(row,column,item);
    QTableWidgetItem *item2 = new QTableWidgetItem();
    item2->setText(inreg.getval());
    ui->tableWidget->setItem(row+1,column,item2);
}

void Register::clearTable(){
    ui->tableWidget->clearContents();
}
