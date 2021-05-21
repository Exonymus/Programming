#ifndef SAFEWINDOW_H
#define SAFEWINDOW_H

#include <QMainWindow>
#include "buttonhoverwatcher.h"
#include "graphics.h"

namespace Ui {
class SafeWindow;
}

class SafeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SafeWindow(QWidget *parent = nullptr);

    ~SafeWindow();

signals:
    void MainWindow();

    void Victory(int sum);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_12_pressed();

    void on_pushButton_12_released();

    void on_pushButton_12_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_5_pressed();

    void on_pushButton_5_released();

    void on_pushButton_6_pressed();

    void on_pushButton_6_released();

    void on_pushButton_7_pressed();

    void on_pushButton_7_released();

    void on_pushButton_8_pressed();

    void on_pushButton_8_released();

    void on_pushButton_9_pressed();

    void on_pushButton_9_released();

    void on_pushButton_10_pressed();

    void on_pushButton_10_released();

    void on_pushButton_11_pressed();

    void on_pushButton_11_released();

    void on_pushButton_2_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

private:
    Ui::SafeWindow *ui;

    void Loss();

    void Open(QChar ch);
};

#endif // SAFEWINDOW_H
