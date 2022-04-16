#include <QFileDialog>
#include <QMessageBox>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");


    connect(ui->actionLoad, &QAction::triggered, this,
            &MainWindow::on_actionLoad_clicked);

    connect(ui->actionSave, &QAction::triggered, this,
            &MainWindow::on_actionSave_clicked);

    connect(ui->actionInfFile, &QAction::triggered, this,
            &MainWindow::on_actionInfFile_clicked);

    connect(ui->actionInfProgram, &QAction::triggered, this,
            &MainWindow::on_actionInfProgram_clicked);

    connect(ui->actionInfDeveloper, &QAction::triggered, this,
            &MainWindow::on_actionInfDeveloper_clicked);
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = QUIT;
    manager_actions(request);
    delete ui;
}

error_t MainWindow::draw()
{
    auto rcontent = ui->graphicsView->contentsRect();
    ui->graphicsView->scene()->setSceneRect(0, 0, rcontent.width(),
                                      rcontent.height());

    request_t request;
    request.action = DRAW;
    request.view = {.scene = ui->graphicsView->scene(),
                   .width =  ui->graphicsView->scene()->width(),
                   .height =  ui->graphicsView->scene()->height()
                   };

    return manager_actions(request);
}

void MainWindow::on_actionSave_clicked()
{
    QString path = QFileDialog::getSaveFileName();

    request_t request;
    request.action = SAVE;
    request.filename = path.toUtf8().data();

    error_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_actionLoad_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    request_t request;
    request.action = DOWNLOAD;
    request.filename = path.toUtf8().data();

    error_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_actionInfFile_clicked()
{
    QMessageBox::information(0, "Информация о входном файле", "Файл должен содержать количество точек\n"
                                                              "Затем уже должны идти аргументы в строго в порядке:\n"
                                                              "x y z\n"
                                                              "После ввода все точек нужно отметить количество ребер\n"
                                                              "Затем уже идут нумерация связи точек(нумериция с 0) связи в любом порядке:\n"
                                                              "точка_1 точка_2\n\n"
                                                              "PS. Проверяй данные в файле!");
}

void MainWindow::on_actionInfProgram_clicked()
{
    QMessageBox::information(0, "Информация о программа", "Привет, эта программа - 3D Viewer, созданные в целе\n"
                                                          "сдачи лабораторной работы и предназначения для раcмотренние\n"
                                                          "каркасных 3D моделей и не более.");
}

void MainWindow::on_actionInfDeveloper_clicked()
{
    QMessageBox::information(0, "Информация о разработчике", "Разработчиком данной программы, является студент\n"
                                                             "МГТУ им. Н.Э.Баумана, ИУ7-46Б, Мансуров Владислав.");
}

void MainWindow::on_buttonMoving_clicked()
{
    request_t request;
    request.action = MOVE;
    request.move = {
           .dx = ui->enterXMoving->value(),
           .dy = ui->enterYMoving->value(),
           .dz = ui->enterZMoving->value()
    };

    error_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}

void MainWindow::on_buttonTurn_clicked()
{
    request_t request;
    request.action = ROTATE;
    request.rotate = {
           .angle_x = ui->enterXTurn->value(),
           .angle_y = ui->enterYTurn->value(),
           .angle_z = ui->enterZTurn->value()
    };

    error_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}


void MainWindow::on_buttonScale_clicked()
{
    request_t request;
    request.action = SCALE;
    request.scale = {
           .kx = ui->enterXScale->value(),
           .ky = ui->enterYScale->value(),
           .kz = ui->enterZScale->value()
    };

    error_t rc = manager_actions(request);
    if (rc)
        error_message(rc);
    else
    {
        rc = draw();
        if (rc)
            error_message(rc);
    }
}
