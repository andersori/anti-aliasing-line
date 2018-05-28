#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dimencao->setValue(ui->tela->get_dimensao());
}

MainWindow::~MainWindow()
{
    delete ui;
}
