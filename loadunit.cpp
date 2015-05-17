#include "loadunit.h"
#include "ui_loadunit.h"
//#include "def.h"

LoadUnit::LoadUnit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadUnit)
{
    ui->setupUi(this);
}

LoadUnit::~LoadUnit()
{
    delete ui;
}

void LoadUnit::setTable(int row,int column,LU inlu){
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(inlu.getName());
    ui->tableWidget->setItem(row,column,item);
    QTableWidgetItem *item2 = new QTableWidgetItem();
    if(inlu.getState() == TRUE){
        item2->setText("Yes");
    }else{
        item2->setText("No");
    }
    ui->tableWidget->setItem(row,column+1,item2);
    QTableWidgetItem *item3 = new QTableWidgetItem();
    item3->setText(inlu.getAddr());
    ui->tableWidget->setItem(row,column+2,item3);
    QTableWidgetItem *item4 = new QTableWidgetItem();
    item4->setText(inlu.getVal());
    ui->tableWidget->setItem(row,column+3,item4);
}

void LoadUnit::clearTable(){
    ui->tableWidget->clearContents();
}
