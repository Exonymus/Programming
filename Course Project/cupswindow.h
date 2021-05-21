#ifndef CUPSWINDOW_H
#define CUPSWINDOW_H

#include <QMainWindow>
#include "buttonhoverwatcher.h"
#include "graphics.h"

namespace Ui {
class CupsWindow;
}

class CupsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CupsWindow(QWidget *parent = nullptr);

    ~CupsWindow();

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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::CupsWindow *ui;

    QTimer *timer;

    void Result(int victory, QString side);

    void finalResult();
};

#endif // CUPSWINDOW_H
