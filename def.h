#ifndef DEF_H
#define DEF_H
#include <QWidget>

enum StationType{
    ADD,
    MULTI
};

enum State{
    WAIT,
    LANCH,
    EXEC,
    WRITE,
    FINISH
};

enum InsType{
    LOAD,//load.d
    PM,//float operation plus minus
    MD//multiply division
};

//--------------------------------------- InStat ---------------------------------------------------------
class InStat{
public:

    InStat(QString inins,QString inarg1,QString inarg2,QString inarg3,State instat);

    QString getIns();

    void setState(State instat);

    State getState();

    InsType getType();

    QString getArg1();

    QString getArg2();

    QString getArg3();

    QString getlanchtime();

    void setlaunchtime(QString intime);

    QString getexectime();

    void setexectime(QString intime);

    QString getwritetime();

    void setwritetime(QString intime);

private:
    QString ins;
    QString arg1;
    QString arg2;
    QString arg3;
    State stat;
    InsType type;
    QString lanchtime;
    QString exectime;
    QString writetime;
};

//----------------------------------------- LU ------------------------------------------------
class LU{
public:

    LU(QString inname);

    void setLU(bool inbusy,QString inaddr,QString inval);

    void setName(QString inname);

    QString getName();

    int getNum(QString inname);

    bool getState();

    void setState(bool inbusy);

    void setAddr(QString inaddr);

    QString getAddr();

    void setVal(QString inval);

    QString getVal();

private:
    QString name;
    bool busy;
    QString addr;
    QString val;
};

//------------------------------------ Reg ----------------------------------------------
class Reg{
public:
    Reg();

    Reg(QString inname);

    void setName(QString inname);

    QString getqi();

    void setqi(QString inqi);

    QString getval();

    void setval(QString inval);

private:
    QString name;
    QString qi;
    QString val;
};

//-------------------------------- ReStation --------------------------------------------------
class ReStation{
public:
    ReStation(QString inname);

    ReStation(StationType intype,QString inname,bool instate,
            QString inop,QString invj,QString invk,QString inqj,QString inqk);

    StationType getstationtype();
    void setstationtype(StationType in);

    QString getname();
    void setname(QString in);

    bool getstate();
    void setstate(bool in);

    QString getop();
    void setop(QString in);

    QString getvj();
    void setvj(QString in);

    QString getvk();
    void setvk(QString in);

    QString getqj();
    void setqj(QString in);

    QString getqk();
    void setqk(QString in);

    int gettime();
    void settime(int intime);

private:
    StationType tp;
    int time;
    QString name;
    bool busy;
    QString op;
    QString vj;
    QString vk;
    QString qj;
    QString qk;

};

#endif // DEF_H
