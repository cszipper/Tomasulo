#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "def.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exec_clicked()
{
    clearInstructions();
    code = "";
    setmessage(TRUE);
    //get current instructions
    QString tmp;
    if((tmp = ui->comboBox_cmd_1->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_1->currentText(),
                          ui->comboBox_num_1->currentText(),
                          ui->comboBox_reg_1->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_2->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_2->currentText(),
                          ui->comboBox_num_2->currentText(),
                          ui->comboBox_reg_2->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_3->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_3->currentText(),
                          ui->comboBox_num_3->currentText(),
                          ui->comboBox_reg_3->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_4->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_4->currentText(),
                          ui->comboBox_num_4->currentText(),
                          ui->comboBox_reg_4->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_5->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_5->currentText(),
                          ui->comboBox_num_5->currentText(),
                          ui->comboBox_reg_5->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_6->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_6->currentText(),
                          ui->comboBox_num_6->currentText(),
                          ui->comboBox_reg_6->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_7->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_7->currentText(),
                          ui->comboBox_num_7->currentText(),
                          ui->comboBox_reg_7->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_8->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_8->currentText(),
                          ui->comboBox_num_8->currentText(),
                          ui->comboBox_reg_8->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_9->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_9->currentText(),
                          ui->comboBox_num_9->currentText(),
                          ui->comboBox_reg_9->currentText(),
                          WAIT);
    }
    if((tmp = ui->comboBox_cmd_10->currentText()) != "NOP"){
        addInstruction(tmp,ui->comboBox_fx_10->currentText(),
                          ui->comboBox_num_10->currentText(),
                          ui->comboBox_reg_10->currentText(),
                          WAIT);
    }

    t_load = ui->lineEdit_load->text().toInt(NULL,10);
    t_plus = ui->lineEdit_plusminus->text().toInt(NULL,10);
    t_multiply = ui->lineEdit_multiply->text().toInt(NULL,10);
    t_division = ui->lineEdit_division->text().toInt(NULL,10);
}

bool MainWindow::getmessage(){
    return MESSAGE;
}

void MainWindow::init(){
    ui->comboBox_cmd_1->setCurrentIndex(0);
    ui->comboBox_cmd_2->setCurrentIndex(0);
    ui->comboBox_cmd_3->setCurrentIndex(0);
    ui->comboBox_cmd_4->setCurrentIndex(0);
    ui->comboBox_cmd_5->setCurrentIndex(0);
    ui->comboBox_cmd_6->setCurrentIndex(0);
    ui->comboBox_cmd_7->setCurrentIndex(0);
    ui->comboBox_cmd_8->setCurrentIndex(0);
    ui->comboBox_cmd_9->setCurrentIndex(0);
    ui->comboBox_cmd_10->setCurrentIndex(0);
    ui->lineEdit_division->setText("40");
    ui->lineEdit_load->setText("2");
    ui->lineEdit_multiply->setText("10");
    ui->lineEdit_plusminus->setText("2");
    ui->textBrowser_CurrentCycle->setText("");
    is.clearTable();
    lu.clearTable();
    reg.clearTable();
    rs.clearTable();
    Instructions.clear();
    Loadunits.clear();
    Registers.clear();
    AddUnits.clear();
    MultUnits.clear();
    cycles = 0;
    M = 0;
    code = "";
    ui->pushButton_exec->setEnabled(TRUE);
    setmessage(FALSE);
    addLoad("Load0");
    addLoad("Load1");
    addLoad("Load2");
    int i = 0;
    for(;i<16;i++){
        addRegister();
    }
    addAdd("Add0");
    addAdd("Add1");
    addAdd("Add2");
    addMult("Mult0");
    addMult("Mult1");
}

void MainWindow::setmessage(bool value){
    MESSAGE = value;
    if(MESSAGE){
        ui->groupBox_config->setDisabled(TRUE);
        ui->groupBox_cmd->setEnabled(TRUE);
        ui->groupBox_code->setEnabled(TRUE);
        ui->groupBox_CurrentCycle->setEnabled(TRUE);
        ui->pushButton_forward1->setEnabled(TRUE);
        ui->pushButton_forward5->setEnabled(TRUE);
        ui->pushButton_go->setEnabled(TRUE);
        lu.show();
        is.show();
        reg.show();
        rs.show();
    }else{
        ui->groupBox_config->setEnabled(TRUE);
        ui->groupBox_cmd->setDisabled(TRUE);
        ui->groupBox_code->setDisabled(TRUE);
        ui->groupBox_CurrentCycle->setDisabled(TRUE);
        lu.hide();
        is.hide();
        reg.hide();
        rs.hide();
    }
}

void MainWindow::on_pushButton_quit_clicked()
{
    setmessage(FALSE);
    ui->textBrowser_code->setText("");
    cycles = 0;
    ui->pushButton_exec->setDisabled(TRUE);
}

void MainWindow::on_pushButton_exit_clicked()
{
    lu.close();
    is.close();
    reg.close();
    rs.close();
    close();
}

void MainWindow::on_comboBox_cmd_1_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_1->clear();
        ui->comboBox_fx_1->addItem("NULL");
        ui->comboBox_num_1->clear();
        ui->comboBox_num_1->addItem("NULL");
        ui->comboBox_reg_1->clear();
        ui->comboBox_reg_1->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_1->clear();
        ui->comboBox_fx_1->addItems(fxitems);
        ui->comboBox_num_1->clear();
        ui->comboBox_num_1->addItems(numitems);
        ui->comboBox_reg_1->clear();
        ui->comboBox_reg_1->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_1->clear();
        ui->comboBox_fx_1->addItems(fxitems);
        ui->comboBox_num_1->clear();
        ui->comboBox_num_1->addItems(fxitems);
        ui->comboBox_reg_1->clear();
        ui->comboBox_reg_1->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_2_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_2->clear();
        ui->comboBox_fx_2->addItem("NULL");
        ui->comboBox_num_2->clear();
        ui->comboBox_num_2->addItem("NULL");
        ui->comboBox_reg_2->clear();
        ui->comboBox_reg_2->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_2->clear();
        ui->comboBox_fx_2->addItems(fxitems);
        ui->comboBox_num_2->clear();
        ui->comboBox_num_2->addItems(numitems);
        ui->comboBox_reg_2->clear();
        ui->comboBox_reg_2->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_2->clear();
        ui->comboBox_fx_2->addItems(fxitems);
        ui->comboBox_num_2->clear();
        ui->comboBox_num_2->addItems(fxitems);
        ui->comboBox_reg_2->clear();
        ui->comboBox_reg_2->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_3_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_3->clear();
        ui->comboBox_fx_3->addItem("NULL");
        ui->comboBox_num_3->clear();
        ui->comboBox_num_3->addItem("NULL");
        ui->comboBox_reg_3->clear();
        ui->comboBox_reg_3->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_3->clear();
        ui->comboBox_fx_3->addItems(fxitems);
        ui->comboBox_num_3->clear();
        ui->comboBox_num_3->addItems(numitems);
        ui->comboBox_reg_3->clear();
        ui->comboBox_reg_3->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_3->clear();
        ui->comboBox_fx_3->addItems(fxitems);
        ui->comboBox_num_3->clear();
        ui->comboBox_num_3->addItems(fxitems);
        ui->comboBox_reg_3->clear();
        ui->comboBox_reg_3->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_4_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_4->clear();
        ui->comboBox_fx_4->addItem("NULL");
        ui->comboBox_num_4->clear();
        ui->comboBox_num_4->addItem("NULL");
        ui->comboBox_reg_4->clear();
        ui->comboBox_reg_4->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_4->clear();
        ui->comboBox_fx_4->addItems(fxitems);
        ui->comboBox_num_4->clear();
        ui->comboBox_num_4->addItems(numitems);
        ui->comboBox_reg_4->clear();
        ui->comboBox_reg_4->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_4->clear();
        ui->comboBox_fx_4->addItems(fxitems);
        ui->comboBox_num_4->clear();
        ui->comboBox_num_4->addItems(fxitems);
        ui->comboBox_reg_4->clear();
        ui->comboBox_reg_4->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_5_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_5->clear();
        ui->comboBox_fx_5->addItem("NULL");
        ui->comboBox_num_5->clear();
        ui->comboBox_num_5->addItem("NULL");
        ui->comboBox_reg_5->clear();
        ui->comboBox_reg_5->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_5->clear();
        ui->comboBox_fx_5->addItems(fxitems);
        ui->comboBox_num_5->clear();
        ui->comboBox_num_5->addItems(numitems);
        ui->comboBox_reg_5->clear();
        ui->comboBox_reg_5->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_5->clear();
        ui->comboBox_fx_5->addItems(fxitems);
        ui->comboBox_num_5->clear();
        ui->comboBox_num_5->addItems(fxitems);
        ui->comboBox_reg_5->clear();
        ui->comboBox_reg_5->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_6_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_6->clear();
        ui->comboBox_fx_6->addItem("NULL");
        ui->comboBox_num_6->clear();
        ui->comboBox_num_6->addItem("NULL");
        ui->comboBox_reg_6->clear();
        ui->comboBox_reg_6->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_6->clear();
        ui->comboBox_fx_6->addItems(fxitems);
        ui->comboBox_num_6->clear();
        ui->comboBox_num_6->addItems(numitems);
        ui->comboBox_reg_6->clear();
        ui->comboBox_reg_6->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_6->clear();
        ui->comboBox_fx_6->addItems(fxitems);
        ui->comboBox_num_6->clear();
        ui->comboBox_num_6->addItems(fxitems);
        ui->comboBox_reg_6->clear();
        ui->comboBox_reg_6->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_7_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_7->clear();
        ui->comboBox_fx_7->addItem("NULL");
        ui->comboBox_num_7->clear();
        ui->comboBox_num_7->addItem("NULL");
        ui->comboBox_reg_7->clear();
        ui->comboBox_reg_7->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_7->clear();
        ui->comboBox_fx_7->addItems(fxitems);
        ui->comboBox_num_7->clear();
        ui->comboBox_num_7->addItems(numitems);
        ui->comboBox_reg_7->clear();
        ui->comboBox_reg_7->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_7->clear();
        ui->comboBox_fx_7->addItems(fxitems);
        ui->comboBox_num_7->clear();
        ui->comboBox_num_7->addItems(fxitems);
        ui->comboBox_reg_7->clear();
        ui->comboBox_reg_7->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_8_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_8->clear();
        ui->comboBox_fx_8->addItem("NULL");
        ui->comboBox_num_8->clear();
        ui->comboBox_num_8->addItem("NULL");
        ui->comboBox_reg_8->clear();
        ui->comboBox_reg_8->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_8->clear();
        ui->comboBox_fx_8->addItems(fxitems);
        ui->comboBox_num_8->clear();
        ui->comboBox_num_8->addItems(numitems);
        ui->comboBox_reg_8->clear();
        ui->comboBox_reg_8->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_8->clear();
        ui->comboBox_fx_8->addItems(fxitems);
        ui->comboBox_num_8->clear();
        ui->comboBox_num_8->addItems(fxitems);
        ui->comboBox_reg_8->clear();
        ui->comboBox_reg_8->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_9_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_9->clear();
        ui->comboBox_fx_9->addItem("NULL");
        ui->comboBox_num_9->clear();
        ui->comboBox_num_9->addItem("NULL");
        ui->comboBox_reg_9->clear();
        ui->comboBox_reg_9->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_9->clear();
        ui->comboBox_fx_9->addItems(fxitems);
        ui->comboBox_num_9->clear();
        ui->comboBox_num_9->addItems(numitems);
        ui->comboBox_reg_9->clear();
        ui->comboBox_reg_9->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_9->clear();
        ui->comboBox_fx_9->addItems(fxitems);
        ui->comboBox_num_9->clear();
        ui->comboBox_num_9->addItems(fxitems);
        ui->comboBox_reg_9->clear();
        ui->comboBox_reg_9->addItems(fxitems);
    }
    }
}

void MainWindow::on_comboBox_cmd_10_currentIndexChanged(int index)
{
    switch(index){
    case 0:{
        ui->comboBox_fx_10->clear();
        ui->comboBox_fx_10->addItem("NULL");
        ui->comboBox_num_10->clear();
        ui->comboBox_num_10->addItem("NULL");
        ui->comboBox_reg_10->clear();
        ui->comboBox_reg_10->addItem("NULL");
        break;
    }
    case 1:{
        QStringList fxitems;
        QStringList numitems;
        QStringList regitems;
        int i = 0;
        for(;i<32;i+=1){
            QString flag1 = "F";
            QString flag2 = "R";
            if(i%2==0) fxitems.append(flag1+QString::number(i));
            numitems.append(QString::number(i));
            regitems.append(flag2+QString::number(i));
        }
        ui->comboBox_fx_10->clear();
        ui->comboBox_fx_10->addItems(fxitems);
        ui->comboBox_num_10->clear();
        ui->comboBox_num_10->addItems(numitems);
        ui->comboBox_reg_10->clear();
        ui->comboBox_reg_10->addItems(regitems);
        break;
    }
    default:{
        QStringList fxitems;
        int i = 0;
        for(;i<32;i+=2){
            QString flag1 = "F";
            fxitems.append(flag1+QString::number(i));
        }
        ui->comboBox_fx_10->clear();
        ui->comboBox_fx_10->addItems(fxitems);
        ui->comboBox_num_10->clear();
        ui->comboBox_num_10->addItems(fxitems);
        ui->comboBox_reg_10->clear();
        ui->comboBox_reg_10->addItems(fxitems);
    }
    }
}

void MainWindow::on_pushButton_reset_clicked()
{
    init();
}

void MainWindow::on_pushButton_forward1_clicked()
{
   if(simulate()){
       ui->pushButton_forward1->setDisabled(TRUE);
       ui->pushButton_forward5->setDisabled(TRUE);
       ui->pushButton_go->setDisabled(TRUE);
       QString mess = "FINISHED ";
       QMessageBox::information(NULL,tr("debug"),mess);
   }
}

void MainWindow::on_pushButton_forward5_clicked()
{
    int i = 5;
    while(i--){
        if(simulate()){
            ui->pushButton_forward1->setDisabled(TRUE);
            ui->pushButton_forward5->setDisabled(TRUE);
            ui->pushButton_go->setDisabled(TRUE);
            QString mess = "FINISHED ";
            QMessageBox::information(NULL,tr("debug"),mess);
            break;
        }
    }
}

void MainWindow::on_pushButton_go_clicked()
{
    while(simulate()){}
    ui->pushButton_forward1->setDisabled(TRUE);
    ui->pushButton_forward5->setDisabled(TRUE);
    ui->pushButton_go->setDisabled(TRUE);
    QString mess = "FINISHED ";
    QMessageBox::information(NULL,tr("debug"),mess);
}

bool MainWindow::simulate(){
    HasLaunched = FALSE;//have 1 ins launched,jump to next cycle
    bool isFinished = TRUE;
    int i;
    int r;
    bool checked[Instructions.size()];
    memset(checked,0,sizeof(checked));
    //QString mess1 = "curcycle " + QString::number(cycles);
    //QMessageBox::information(NULL,tr("debug"),mess1);
    for(i = 0;i<Instructions.size();i++){
        if(Instructions[i].getState()==WAIT){
            isFinished = FALSE;
            if(HasLaunched==FALSE){
                if(Instructions[i].getType() == PM && (r=blankAdd())!=-1){
                    Instructions[i].setState(LANCH);
                    HasLaunched = TRUE;
                    rbuffer[i] = r;
                }
                else if(Instructions[i].getType() == MD && (r=blankMult())!=-1){
                    Instructions[i].setState(LANCH);
                    HasLaunched = TRUE;
                    rbuffer[i] = r;
                }
                else if(Instructions[i].getType() == LOAD && (r=blankLoad())!=-1){
                    Instructions[i].setState(LANCH);
                    HasLaunched = TRUE;
                    rbuffer[i] = r;
                }
            }
        }
        else if(Instructions[i].getState()==LANCH){
            Instructions[i].setlaunchtime(QString::number(cycles));
            isFinished = FALSE;
            r = rbuffer[i];
            QStringList inslist = Instructions[i].getIns().split(" ",QString::SkipEmptyParts);
            QString curins = inslist[0];
            if(Instructions[i].getType() == PM){
                int arg2 = processArg(Instructions[i].getArg2()) / 2;//f0 f2...
                if(Registers[arg2].getqi() != ""){
                    AddUnits[r].setqj(Registers[arg2].getqi());
                }else{
                    AddUnits[r].setvj("R[" + Instructions[i].getArg2() + "]");
                    AddUnits[r].setqj("");
                }
                int arg3 = processArg(Instructions[i].getArg3()) / 2;
                if(Registers[arg3].getqi() != ""){
                    AddUnits[r].setqk(Registers[arg3].getqi());
                }else{
                    AddUnits[r].setvk("R[" + Instructions[i].getArg3() + "]");
                    AddUnits[r].setqk("");
                }
                if(curins == "ADD.D") AddUnits[r].setop("+");
                if(curins == "SUB.D") AddUnits[r].setop("-");
                AddUnits[r].setstate(TRUE);
                int arg1 = processArg(Instructions[i].getArg1()) / 2;
                Registers[arg1].setqi("Add" + QString::number(r));
            }
            else if(Instructions[i].getType() == MD){
                int arg2 = processArg(Instructions[i].getArg2()) / 2;//f0 f2...
                if(Registers[arg2].getqi() != ""){
                    MultUnits[r].setqj(Registers[arg2].getqi());
                }else{
                    MultUnits[r].setvj("R[" + Instructions[i].getArg2() + "]");
                    MultUnits[r].setqj("");
                }
                int arg3 = processArg(Instructions[i].getArg3()) / 2;
                if(Registers[arg3].getqi() != ""){
                    MultUnits[r].setqk(Registers[arg3].getqi());
                }else{
                    MultUnits[r].setvk("R[" + Instructions[i].getArg3() + "]");
                    MultUnits[r].setqk("");
                }
                MultUnits[r].setstate(TRUE);
                if(curins == "MULT.D") MultUnits[r].setop("*");
                if(curins == "DIV.D") MultUnits[r].setop("/");
                int arg1 = processArg(Instructions[i].getArg1()) / 2;
                Registers[arg1].setqi("Mult" + QString::number(r));
            }
            else if(Instructions[i].getType() == LOAD){
                int arg1 = processArg(Instructions[i].getArg1()) / 2;
                QString arg2 = Instructions[i].getArg2();
                //something different from the book
                //there is no need to check arg3's qi because it is empty always
                Loadunits[r].setAddr(arg2);
                Loadunits[r].setState(TRUE);
                Registers[arg1].setqi("Load" + QString::number(r));
            }
            Instructions[i].setState(EXEC);
            times[i] = 0;
        }
        else if(Instructions[i].getState() == EXEC){
            QStringList inslist = Instructions[i].getIns().split(" ",QString::SkipEmptyParts);
            QString curins = inslist[0];
            r = rbuffer[i];
            if(Instructions[i].getType() == PM && AddUnits[r].getqj() == "" && AddUnits[r].getqk() == ""){
                if(times[i]==0) Instructions[i].setexectime(QString::number(cycles) + " ~ ");
                times[i]++;
                AddUnits[r].settime(times[i]);
                if(times[i] == t_plus){
                    if(curins == "ADD.D"){
                        result[i] = AddUnits[r].getvj() + "+" + AddUnits[r].getvk();
                    }else if(curins == "SUB.D"){
                        result[i] = AddUnits[r].getvj() + "-" + AddUnits[r].getvk();
                    }
                    Instructions[i].setexectime(Instructions[i].getexectime() + QString::number(cycles));
                    Instructions[i].setState(WRITE);
                    checked[i]  = TRUE;
                }
            }
            if(Instructions[i].getType() == MD && MultUnits[r].getqj() == "" && MultUnits[r].getqk() == ""){
                if(times[i]==0) Instructions[i].setexectime(QString::number(cycles) + " ~ ");
                times[i]++;
                if(curins == "MULT.D"){
                    MultUnits[r].settime(times[i]);
                    if(times[i] == t_multiply){
                        result[i] = MultUnits[r].getvj() + "*" + MultUnits[r].getvk();
                        Instructions[i].setexectime(Instructions[i].getexectime() + QString::number(cycles));
                        Instructions[i].setState(WRITE);
                        checked[i]  = TRUE;
                    }
                }else if(curins == "DIV.D"){
                    MultUnits[r].settime(times[i]);
                    if(times[i] == t_division){
                        result[i] = MultUnits[r].getvj() + "/" + MultUnits[r].getvk();
                        Instructions[i].setexectime(Instructions[i].getexectime() + QString::number(cycles));
                        Instructions[i].setState(WRITE);
                        checked[i]  = TRUE;
                    }
                }
            }
            if(Instructions[i].getType() == LOAD){
                if(times[i]==0) Instructions[i].setexectime(QString::number(cycles) + " ~ ");
                times[i]++;
                if(times[i] == t_load){
                    Loadunits[r].setAddr("R[" + Instructions[i].getArg3() + "]" + "+" + Loadunits[r].getAddr());
                    Loadunits[r].setVal("M[" + Loadunits[r].getAddr() + "]");
                    result[i] = "M[" + Loadunits[r].getAddr() + "]";
                    Instructions[i].setexectime(Instructions[i].getexectime() + QString::number(cycles));
                    Instructions[i].setState(WRITE);
                    checked[i]  = TRUE;
                }
            }
        }
    }
    for(i = 0;i<Instructions.size();i++){
        if(Instructions[i].getState() == WRITE && !checked[i] && CDB == TRUE){
            CDB = FALSE;
            r = rbuffer[i];
//            QString mess = "WRITE " + Instructions[i].getIns() ;
//            QMessageBox::information(NULL,tr("debug"),mess);
            QString key = "";
            Instructions[i].setwritetime(QString::number(cycles));
            if(Instructions[i].getType()==PM){
                key = "Add";
                AddUnits[r].setstate(FALSE);
                AddUnits[r].setvj("");
                AddUnits[r].setvk("");
                AddUnits[r].setop("");
                AddUnits[r].settime(0);
            }
            else if(Instructions[i].getType()==MD){
                key = "Mult";
                MultUnits[r].setstate(FALSE);
                MultUnits[r].setvj("");
                MultUnits[r].setvk("");
                MultUnits[r].setop("");
                MultUnits[r].settime(0);
            }
            else if(Instructions[i].getType()==LOAD){
                key = "Load";
                Loadunits[r].setState(FALSE);
                Loadunits[r].setAddr("");
                Loadunits[r].setVal("");
            }
            int x = 0;
            for(;x<16;x++){
                if(Registers[x].getqi() == (key + QString::number(r)) ){
                    QString mm = newM();
                    code += mm + "=" + result[i] + "\n";
                    result[i] = mm;
                    Registers[x].setval(result[i]);
                    Registers[x].setqi("");
                }
            }
            for(x=0;x<3;x++){
                if (AddUnits[x].getqj() == (key + QString::number(r))){
                    AddUnits[x].setvj(result[i]);
                    AddUnits[x].setqj("");
                }
                if (AddUnits[x].getqk() == (key + QString::number(r))){
                    AddUnits[x].setvk(result[i]);
                    AddUnits[x].setqk("");
                }
            }
            for(x=0;x<2;x++){
                if (MultUnits[x].getqj() == (key + QString::number(r))){
                    MultUnits[x].setvj(result[i]);
                    MultUnits[x].setqj("");
                }
                if (MultUnits[x].getqk() == (key + QString::number(r))){
                    MultUnits[x].setvk(result[i]);
                    MultUnits[x].setqk("");
                }
            }
            Instructions[i].setState(FINISH);
        }
    }
    for(i = 0;i<Instructions.size();i++){
        if(Instructions[i].getState()==FINISH){
            //pass
            //QString mess = "FINISH " + Instructions[i].getIns() ;
            //QMessageBox::information(NULL,tr("debug"),mess);
        }
    }

    int x;
    for(x = 0;x<Instructions.size();x++){
        if(Instructions[x].getState() != FINISH) {
            isFinished = FALSE;
            break;
        }
    }
    refreshTable();
    ui->textBrowser_CurrentCycle->setText(QString::number(cycles));
    cycles ++;
    CDB = TRUE;
    return isFinished;
}

void MainWindow::refreshTable(){
    int i;
    for(i = 0;i<Instructions.size();i++){
        is.setTable(i,0,Instructions[i]);
    }
    for(i = 0;i<3;i++){
        lu.setTable(i,0,Loadunits[i]);
    }
    for(i = 0;i<3;i++){
        rs.setTable(i,0,AddUnits[i]);
    }
    for(i = 0;i<2;i++){
        rs.setTable(i+3,0,MultUnits[i]);
    }
    for(i = 0;i<15;i++){
        reg.setTable(0,i,Registers[i]);
    }
    ui->textBrowser_code->setText(code);
}

int MainWindow::blankAdd(){
    int tmp;
    for(tmp = 0;tmp<3;tmp++){
        if(AddUnits[tmp].getstate() == FALSE){
            return tmp;
        }
    }
    return -1;
}

int MainWindow::blankMult(){
    int tmp;
    for(tmp = 0;tmp<2;tmp++){
        if(MultUnits[tmp].getstate() == FALSE){
            return tmp;
        }
    }
    return -1;
}

int MainWindow::blankLoad(){
    int tmp;
    for(tmp = 0;tmp<3;tmp++){
        if(Loadunits[tmp].getState() == FALSE){
            return tmp;
        }
    }
    return -1;
}

int MainWindow::processArg(QString arg){
    return arg.remove(0,1).toInt(NULL,10);
}

QString MainWindow::newM(){
    return "M" + QString::number(++M);
}
