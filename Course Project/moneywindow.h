#ifndef MONEYWINDOW_H
#define MONEYWINDOW_H

#include <QMainWindow>
#include "buttonhoverwatcher.h"
#include "graphics.h"

namespace Ui {
class MoneyWindow;
}

class MoneyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MoneyWindow(QWidget *parent = nullptr);

    ~MoneyWindow();

signals:
    void MainWindow();

    void Victory(int sum);

private slots:
    void timerAlarm();

    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MoneyWindow *ui;

    QTimer *timer;
};

#endif // MONEYWINDOW_H
