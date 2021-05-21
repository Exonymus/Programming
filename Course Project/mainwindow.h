#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHoverEvent>
#include "buttonhoverwatcher.h"
#include "moneywindow.h"
#include "safewindow.h"
#include "cupswindow.h"
#include "graphics.h"

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
    void Victory(int sum);

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;

    MoneyWindow *sWindow;

    SafeWindow *tWindow;

    CupsWindow *fWindow;
};

#endif // MAINWINDOW_H
