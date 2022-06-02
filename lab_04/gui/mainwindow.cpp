#include "mainwindow.h"

#include <memory>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(500, 500);
    this->layout_ = std::make_unique<QVBoxLayout>();

    this->ui->centralwidget->setLayout(this->layout_.get());

    this->layout_->addWidget(this->my_lift.widget());
}

MainWindow::~MainWindow()
{
    delete ui;
}

