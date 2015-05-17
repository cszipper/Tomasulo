#include "def.h"
#include "mainwindow.h"
//************************************************************************
InStat::InStat(QString inins,QString inarg1,QString inarg2,QString inarg3,State instat){
    ins = inins;
    arg1 = inarg1;
    arg2 = inarg2;
    arg3 = inarg3;
    stat = instat;
    if(inins=="L.D"){
        type = LOAD;
    }
    else if(inins == "ADD.D"){
        type = PM;
    }
    else if(inins == "SUB.D"){
        type = PM;
    }
    else{
        type = MD;
    }
    lanchtime = "";
    exectime = "";
    writetime = "";
}

QString InStat::getIns(){
    return ins + " " + arg1 + " " + arg2 + " "+ arg3;
}

void InStat::setState(State instat){
    stat = instat;
}

State InStat::getState(){
    return stat;
}

InsType InStat::getType(){
    return type;
}

QString InStat::getArg1(){
    return arg1;
}

QString InStat::getArg2(){
    return arg2;
}

QString InStat::getArg3(){
    return arg3;
}

QString InStat::getlanchtime(){
    return lanchtime;
}

void InStat::setlaunchtime(QString intime){
    lanchtime = intime;
}

QString InStat::getexectime(){
    return exectime;
}

void InStat::setexectime(QString intime){
    exectime = intime;
}

QString InStat::getwritetime(){
    return writetime;
}

void InStat::setwritetime(QString intime){
    writetime = intime;
}

//------------------------------------------- MainWindow -----------------------------------------
QString MainWindow::getInstruction(int pos){
    InStat tmp = Instructions[pos];
    return tmp.getIns();
}

int MainWindow::getInstructionNum(){
    return Instructions.size();
}

void MainWindow::clearInstructions(){
    Instructions.clear();
}

void MainWindow::addInstruction(QString inins, QString inarg1,QString inarg2,QString inarg3,State instat){
    InStat tmp(inins,inarg1,inarg2,inarg3,instat);
    Instructions.push_back(tmp);
}

void MainWindow::addLoad(QString inname){
    LU tmp(inname);
    Loadunits.push_back(tmp);
}

void MainWindow::addRegister(){
    Reg tmp;
    Registers.push_back(tmp);
}

void MainWindow::addAdd(QString inname){
    ReStation tmp(inname);
    AddUnits.push_back(tmp);
}

void MainWindow::addMult(QString inname){
    ReStation tmp(inname);
    MultUnits.push_back(tmp);
}

//************************************************************************
LU::LU(QString inname){
    name = inname;
    busy = FALSE;
    addr = "";
    val = "";
}

void LU::setLU(bool inbusy, QString inaddr, QString inval){
    busy = inbusy;
    addr = inaddr;
    val = inval;
}

void LU::setName(QString inname){
    name = inname;
}

QString LU::getName(){
    return name;
}

bool LU::getState(){
    return busy;
}

void LU::setState(bool inbusy){
    busy = inbusy;
}

void LU::setAddr(QString inaddr){
    addr = inaddr;
}

QString LU::getAddr(){
    return addr;
}

void LU::setVal(QString inval){
    val = inval;
}

QString LU::getVal(){
    return val;
}

//************************************************************************
Reg::Reg(){
    name = "";
    qi = "";
    val = "";
}

Reg::Reg(QString inname){
    name = inname;
    qi = "";
    val = "";
}

QString Reg::getqi(){
    return qi;
}

void Reg::setqi(QString inqi){
    qi = inqi;
}

QString Reg::getval(){
    return val;
}

void Reg::setval(QString inval){
    val = inval;
}

//************************************************************************
ReStation::ReStation(QString inname)
{
    name = inname;
    busy = FALSE;
    op = vj = vk = qj = qk = "";
}

ReStation::ReStation(StationType intype,QString inname,bool instate,
                          QString inop,QString invj,QString invk,QString inqj,QString inqk)
{
    tp = intype;
    name = inname;
    busy = instate;
    op = inop;
    vj = invj;
    vk = invk;
    qj = inqj;
    qk = inqk;
}

StationType ReStation::getstationtype(){
    return tp;
}

void ReStation::setstationtype(StationType in){
    tp = in;
}

QString ReStation::getname(){
    return name;
}

void ReStation::setname(QString in){
    name = in;
}

bool ReStation::getstate(){
    return busy;
}

void ReStation::setstate(bool in){
    busy = in;
}

QString ReStation::getop(){
    return op;
}

void ReStation::setop(QString in){
    op = in;
}

QString ReStation::getvj(){
    return vj;
}

void ReStation::setvj(QString in){
    vj  = in;
}

QString ReStation::getvk(){
    return vk;
}

void ReStation::setvk(QString in){
    vk = in;
}

QString ReStation::getqj(){
    return qj;
}

void ReStation::setqj(QString in){
    qj = in;
}

QString ReStation::getqk(){
    return qk;
}

void ReStation::setqk(QString in){
    qk = in;
}

int ReStation::gettime(){
    return time;
}

void ReStation::settime(int intime){
    time = intime;
}
