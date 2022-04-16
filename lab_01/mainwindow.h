#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "actions.h"
#include "errors.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void on_actionLoad_clicked();

    void on_actionSave_clicked();

    void on_actionInfFile_clicked();

    void on_actionInfProgram_clicked();

    void on_actionInfDeveloper_clicked();

private slots:
    error_t draw();

    void on_buttonMoving_clicked();

    void on_buttonTurn_clicked();

    void on_buttonScale_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
