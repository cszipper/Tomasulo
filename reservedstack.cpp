#include "reservedstack.h"
#include "ui_reservedstack.h"
ReservedStack::ReservedStack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReservedStack)
{
    ui->setupUi(this);
}

ReservedStack::~ReservedStack()
{
    delete ui;
}

void ReservedStack::setTable(int row,int column,ReStation inrs){
    QTableWidgetItem *item0 = new QTableWidgetItem();
    item0->setText(QString::number(inrs.gettime()));
    ui->tableWidget->setItem(row,column,item0);
    QTableWidgetItem *item1 = new QTableWidgetItem();
    item1->setText(inrs.getname());
    ui->tableWidget->setItem(row,column+1,item1);
    QTableWidgetItem *item2 = new QTableWidgetItem();
    if(inrs.getstate()==TRUE) item2->setText("Yes");
    else item2->setText("No");
    ui->tableWidget->setItem(row,column+2,item2);
    QTableWidgetItem *item3 = new QTableWidgetItem();
    item3->setText(inrs.getop());
    ui->tableWidget->setItem(row,column+3,item3);
    QTableWidgetItem *item4 = new QTableWidgetItem();
    item4->setText(inrs.getvj());
    ui->tableWidget->setItem(row,column+4,item4);
    QTableWidgetItem *item5 = new QTableWidgetItem();
    item5->setText(inrs.getvk());
    ui->tableWidget->setItem(row,column+5,item5);
    QTableWidgetItem *item6 = new QTableWidgetItem();
    item6->setText(inrs.getqj());
    ui->tableWidget->setItem(row,column+6,item6);
    QTableWidgetItem *item7 = new QTableWidgetItem();
    item7->setText(inrs.getqk());
    ui->tableWidget->setItem(row,column+7,item7);
}

void ReservedStack::clearTable(){
    ui->tableWidget->clearContents();
}
