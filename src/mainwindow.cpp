#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dimencao->setValue(ui->tela->get_dimensao());

    //connect(this->ui->dimencao,SIGNAL(valueChanged(int)), this->ui->tela, SLOT(set_dimensao(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dimencao_valueChanged(int arg1)
{
    if(arg1 != 0){
        this->ui->tela->set_dimensao(arg1);
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == 0)
    {
        this->ui->tela->set_algoritmo(1);
    }
    else
    {
        this->ui->tela->set_algoritmo(2);
    }
}
