#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtCore/QCoreApplication>
#include<QtCore/qmath.h>

QString value = "", total = "";
int fNum, sNum;

bool addBool = false, subtractBool = false, multiplyBool = false, divideBool=false;
bool sinBool = false, cosBool = false, tanBool = false, sqrtBool = false, powBool = false, cubicBool = false, expBool = false, lnBool = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    label = new QLabel("0", this);
    label -> setGeometry(QRect(QPoint(75,25),QSize(50,200)));

    clear_button = new QPushButton("C", this);
    clear_button -> setGeometry(QRect(QPoint(100,300),QSize(50,50)));
    connect(clear_button, SIGNAL(released()), this,SLOT(clear()));

    equals_button = new QPushButton("=", this);
    equals_button -> setGeometry(QRect(QPoint(150,300),QSize(50,50)));
    connect(equals_button, SIGNAL(released()), this,SLOT(equals()));

    add_button = new QPushButton("+", this);
    add_button -> setGeometry(QRect(QPoint(200,150),QSize(50,50)));
    connect(add_button, SIGNAL(released()), this,SLOT(add()));

    subtract_button = new QPushButton("-", this);
    subtract_button -> setGeometry(QRect(QPoint(200,200),QSize(50,50)));
    connect(subtract_button, SIGNAL(released()), this,SLOT(subtract()));

    multiply_button = new QPushButton("X", this);
    multiply_button -> setGeometry(QRect(QPoint(200,250),QSize(50,50)));
    connect(multiply_button, SIGNAL(released()), this,SLOT(multiply()));

    divide_button = new QPushButton(":", this);
    divide_button -> setGeometry(QRect(QPoint(200,300),QSize(50,50)));
    connect(divide_button, SIGNAL(released()), this,SLOT(divide()));

    sin_button = new QPushButton("sin", this);
    sin_button -> setGeometry(QRect(QPoint(250,150),QSize(50,50)));
    connect(sin_button, SIGNAL(released()), this,SLOT(sin()));

    cos_button = new QPushButton("cos", this);
    cos_button -> setGeometry(QRect(QPoint(250,200),QSize(50,50)));
    connect(cos_button, SIGNAL(released()), this,SLOT(cos()));

    tan_button = new QPushButton("tan", this);
    tan_button -> setGeometry(QRect(QPoint(250,250),QSize(50,50)));
    connect(tan_button, SIGNAL(released()), this,SLOT(tan()));

    sqrt_button = new QPushButton("sqrt", this);
    sqrt_button -> setGeometry(QRect(QPoint(250,300),QSize(50,50)));
    connect(sqrt_button, SIGNAL(released()), this,SLOT( sqrt()));

    pow_button = new QPushButton("^2", this);
    pow_button -> setGeometry(QRect(QPoint(250,350),QSize(50,50)));
    connect(pow_button, SIGNAL(released()), this,SLOT(pow()));

    cubic_button = new QPushButton("^3", this);
    cubic_button -> setGeometry(QRect(QPoint(200,350),QSize(50,50)));
    connect(cubic_button, SIGNAL(released()), this,SLOT(cubic()));

    exp_button = new QPushButton("exp", this);
    exp_button -> setGeometry(QRect(QPoint(150,350),QSize(50,50)));
    connect(exp_button, SIGNAL(released()), this,SLOT(exp()));

    ln_button = new QPushButton("ln", this);
    ln_button -> setGeometry(QRect(QPoint(100,350),QSize(50,50)));
    connect(ln_button, SIGNAL(released()), this,SLOT(ln()));



    for(int i=0; i<10; i++){
        QString digit = QString::number(i);
        buttons[i] = new QPushButton(digit, this);
        connect(buttons[i], SIGNAL(released()), this,SLOT(buttonPushed()));
    }


    setGeo();
}

void MainWindow::buttonPushed() {
    QPushButton *button = (QPushButton*)sender();
    emit numberEmitted(button -> text()[0].digitValue());
    value +=QString::number(button -> text()[0].digitValue());
    label -> setText(value);

}

void MainWindow::setGeo(){
    for(int i =0; i<1; i++){
        buttons[i] -> setGeometry(QRect(QPoint(50,300),QSize(50,50)));
    }
    for(int i =1; i<4; i++){
        buttons[i] -> setGeometry(QRect(QPoint(50*i,250),QSize(50,50)));
    }
    for(int i =4; i<7; i++){
        buttons[i] -> setGeometry(QRect(QPoint(50*(i-3),200),QSize(50,50)));
    }
    for(int i =7; i<10; i++){
        buttons[i] -> setGeometry(QRect(QPoint(50*(i-6),150),QSize(50,50)));
    }

}

void MainWindow::clear(){
    value = "";
    label ->setText(value);

}


void MainWindow:: equals()
{
    sNum = value.toDouble();

    if (addBool){
        total = QString::number(fNum+sNum);
        label -> setText(total);
    }
    if (subtractBool){
        total = QString::number(fNum-sNum);
        label -> setText(total);
    }
    if (multiplyBool){
        total = QString::number(fNum*sNum);
        label -> setText(total);
    }
    if(divideBool){
        total = QString::number(fNum/sNum);
        label -> setText(total);
    }
    if(sinBool){
        total = QString::number(qSin(fNum));
        label -> setText(total);
    }
    if(cosBool){
        total = QString::number(qCos(fNum));
        label -> setText(total);
    }
    if(tanBool){
        total = QString::number(qTan(fNum));
        label -> setText(total);
    }
    if(sqrtBool){
        total = QString::number(qSqrt(fNum));
        label -> setText(total);
    }
    if(powBool){
        total = QString::number(qPow(fNum,2));
        label -> setText(total);
    }
    if(cubicBool){
        total = QString::number(qPow(fNum,3));
        label -> setText(total);
    }
    if(expBool){
        total = QString::number(qExp(fNum));
        label -> setText(total);
    }
    if(lnBool){
        total = QString::number(qLn(fNum));
        label -> setText(total);
    }

    fNum = 0;
    sNum = 0;
}
void MainWindow::add() {
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    addBool = true;
}
void MainWindow::subtract(){

    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    subtractBool = true;
}

void MainWindow::multiply(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    multiplyBool = true;

}

void MainWindow::divide(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    divideBool = true;
}


void MainWindow::sin(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    sinBool = true;
}

void MainWindow::cos(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    cosBool = true;
}

void MainWindow::tan(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    tanBool = true;
}

void MainWindow::sqrt(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    sqrtBool = true;
}

void MainWindow::pow(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    powBool = true;
}

void MainWindow::cubic(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    cubicBool = true;
}

void MainWindow::exp(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    expBool = true;
}

void MainWindow::ln(){
    fNum = value.toDouble();
    value = "";
    label -> setText(value);
    lnBool = true;
}




MainWindow::~MainWindow()
{

}
