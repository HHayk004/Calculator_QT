#include "mainwindow.h"
//#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_buttons(5, std::vector<QPushButton*>(4))
    , m_display(new QLabel("", this))
    //, ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->setGeometry(0, 0, 500, 375);
    this->setMinimumWidth(500);
    this->setMinimumHeight(375);

    m_display->setStyleSheet("background-color: white");

    std::vector<std::vector<QString>> symbols = {
        {"(", ")", "%", "CE"},
        {"7", "8", "9", "/"},
        {"4", "5", "6", "x"},
        {"1", "2", "3", "-"},
        {"0", ".", "=", "+"}
    };

    for (int i = 0; i < m_buttons.size(); ++i)
    {
        for (int j = 0; j < m_buttons[i].size(); ++j)
        {
            m_buttons[i][j] = new QPushButton(this);
            m_buttons[i][j]->setText(symbols[i][j]);
        }
    }
}

double MainWindow::percent(int val, double p) const
{
    return val * p / 100;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    int w = this->size().width();
    int h = this->size().height();

    m_display->setGeometry(0, 0, w, percent(h, 20));

    for (int i = 0; i < m_buttons.size(); ++i)
    {
        for (int j = 0; j < m_buttons[i].size(); ++j)
        {
            double b_x = percent(w, 25 * j);
            double b_y = percent(h, 20 + 16 * i);
            double b_h = percent(w, 25);
            double b_w = percent(h, 16);
            m_buttons[i][j]->setGeometry(b_x, b_y, b_h, b_w);
        }
    }
}

MainWindow::~MainWindow()
{
    //delete ui;
}
