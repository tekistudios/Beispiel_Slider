#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect sliders to change params in OGLWidget
    connect(ui->sliderA, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setParamA(int)));
    connect(ui->sliderB, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setParamB(int)));
    connect(ui->sliderC, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setParamC(int)));
    connect(ui->sliderD, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setParamD(int)));
    connect(ui->sliderE, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(setParamE(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}
