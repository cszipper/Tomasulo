#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loadunit.h"
#include "instructionstate.h"
#include "register.h"
#include "reservedstack.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void init();

    bool getmessage();

    void setmessage(bool);

    void addInstruction(QString inins, QString inarg1,QString inarg2,QString inarg3,State instat);

    QString getInstruction(int pos);

    int getInstructionNum();

    void clearInstructions();

    void addLoad(QString inname);

    void addRegister();

    void addAdd(QString inname);

    void addMult(QString inname);

    void refreshTable();

    int blankAdd();

    int blankMult();

    int blankLoad();

    int processArg(QString arg);

    QString newM();

private slots:
    void on_pushButton_exec_clicked();

    void on_pushButton_quit_clicked();

    void on_pushButton_exit_clicked();

    void on_comboBox_cmd_1_currentIndexChanged(int index);

    void on_comboBox_cmd_2_currentIndexChanged(int index);

    void on_comboBox_cmd_3_currentIndexChanged(int index);

    void on_comboBox_cmd_4_currentIndexChanged(int index);

    void on_comboBox_cmd_5_currentIndexChanged(int index);

    void on_comboBox_cmd_6_currentIndexChanged(int index);

    void on_comboBox_cmd_7_currentIndexChanged(int index);

    void on_comboBox_cmd_8_currentIndexChanged(int index);

    void on_comboBox_cmd_9_currentIndexChanged(int index);

    void on_comboBox_cmd_10_currentIndexChanged(int index);

    void on_pushButton_reset_clicked();

    void on_pushButton_forward1_clicked();

    void on_pushButton_forward5_clicked();

    void on_pushButton_go_clicked();

    bool simulate();

private:
    Ui::MainWindow *ui;
    bool MESSAGE;

    //-------Widget--------
    LoadUnit lu;
    InstructionState is;
    ReservedStack rs;
    Register reg;

    bool CDB;//central data bus
    bool HasLaunched;

    int cycles;
    int t_load;
    int t_plus;
    int t_multiply;
    int t_division;

    //---------vector------------------
    int rbuffer[10];
    QString result[10];
    int times[10];
    std::vector<InStat> Instructions;
    std::vector<LU> Loadunits;
    std::vector<Reg> Registers;
    std::vector<ReStation> AddUnits;
    std::vector<ReStation> MultUnits;

    int M;
    QString code;
};

#endif // MAINWINDOW_H
