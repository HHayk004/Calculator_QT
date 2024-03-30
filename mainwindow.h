#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    virtual void resizeEvent(QResizeEvent* event) override;

private:
    //Ui::MainWindow *ui;
    std::vector<std::string> expr; // sta mej pti tvern u operatornery miajamanak arandzin avelanan
    std::vector<std::vector<QPushButton*>> m_buttons;
    QLabel* m_display;

private:
    double percent(int val, double p) const;

    // stugumneri functianeri ngaragrutyuny stex es avelacnelu
};
#endif // MAINWINDOW_H
