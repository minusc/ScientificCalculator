#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void numberEmitted(int number);

private slots:
    void clear();
    void equals();
    void add();
    void subtract();
    void multiply();
    void divide();
    void sin();
    void cos();
    void tan();
    void sqrt();
    void pow();
    void cubic();
    void exp();
    void ln();

    void buttonPushed();
    void setGeo();

private:
    QLabel *label;
    QPushButton *clear_button;
    QPushButton *equals_button;
    QPushButton *add_button;
    QPushButton *subtract_button;
    QPushButton *multiply_button;
    QPushButton *divide_button;
    QPushButton *sin_button;
    QPushButton *cos_button;
    QPushButton *tan_button;
    QPushButton *sqrt_button;
    QPushButton *pow_button;
    QPushButton *cubic_button;
    QPushButton *exp_button;
    QPushButton *ln_button;

    QPushButton *buttons[10];

};

#endif // MAINWINDOW_H
