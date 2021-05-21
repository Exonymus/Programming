#include "mainwindow.h"
#include "ui_mainwindow.h"

int balance = 800;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(
                "background-image:url(:/StartMenu/Assets/bg.png); background-position: center;");

    butImg(ui->pushButton, ":/StartMenu/Assets/start_bt.png");
    ButtonHoverWatcher * watcher = new ButtonHoverWatcher(this, ":/StartMenu/Assets/start_bt");
    ui->pushButton->installEventFilter(watcher);

    labGif(ui->label, ":/StartMenu/Assets/bg_cat.gif");
    labGif(ui->label_2, ":/StartMenu/Assets/bg_clips.gif");
    labGif(ui->label_3, ":/StartMenu/Assets/bg_cat_2.gif");
    labGif(ui->label_4, ":/StartMenu/Assets/bg_rev.gif");

    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->label_5->hide();

    sWindow = new MoneyWindow();
    tWindow = new SafeWindow();
    fWindow = new CupsWindow();

    connect(sWindow, &MoneyWindow::MainWindow, this, &MainWindow::show);
    connect(tWindow, &SafeWindow::MainWindow, this, &MainWindow::show);
    connect(fWindow, &CupsWindow::MainWindow, this, &MainWindow::show);

    connect(sWindow, &MoneyWindow::Victory, this, &MainWindow::Victory);
    connect(tWindow, &SafeWindow::Victory, this, &MainWindow::Victory);
    connect(fWindow, &CupsWindow::Victory, this, &MainWindow::Victory);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_pressed()
{
   butImg(ui->pushButton, ":/StartMenu/Assets/start_bt_pressed.png");
}

void MainWindow::on_pushButton_released()
{
    butImg(ui->pushButton, ":/StartMenu/Assets/start_bt_hover.png");
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_5->show();
    ui->pushButton->hide();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();

    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_5->setText("Баланс: "+QString::number(balance)+"$");

    butImg(ui->pushButton_2, ":/GameChoice/Assets/cups.png");
    butImg(ui->pushButton_3, ":/GameChoice/Assets/safe.png");
    butImg(ui->pushButton_4, ":/GameChoice/Assets/money.png");

    ButtonHoverWatcher * watcher1 = new ButtonHoverWatcher(this, ":/GameChoice/Assets/cups");
    ui->pushButton_2->installEventFilter(watcher1);

    ButtonHoverWatcher * watcher2 = new ButtonHoverWatcher(this, ":/GameChoice/Assets/safe");
    ui->pushButton_3->installEventFilter(watcher2);

    ButtonHoverWatcher * watcher3 = new ButtonHoverWatcher(this, ":/GameChoice/Assets/money");
    ui->pushButton_4->installEventFilter(watcher3);
}


void MainWindow::on_pushButton_5_clicked()
{
    int award = arc4random() % 2;
    Victory(award);
}

void MainWindow::Victory(int sum)
{
    balance += sum;
    ui->label_5->clear();
    ui->label_5->setText("Баланс: "+QString::number(balance)+"$");

    if (balance < 350)
        ui->pushButton_3->setEnabled(false);
    else
        ui->pushButton_3->setEnabled(true);

    if (balance < 150)
        ui->pushButton_2->setEnabled(false);
    else
        ui->pushButton_2->setEnabled(true);

    if (balance >= 1000)
        ui->pushButton_4->setEnabled(false);
    else
        ui->pushButton_4->setEnabled(true);
}

void MainWindow::on_pushButton_2_pressed()
{
    butImg(ui->pushButton_2, ":/GameChoice/Assets/cups_pressed.png");
}

void MainWindow::on_pushButton_2_released()
{
    butImg(ui->pushButton_2, ":/GameChoice/Assets/cups_hover.png");
}

void MainWindow::on_pushButton_4_pressed()
{
    butImg(ui->pushButton_4, ":/GameChoice/Assets/money_pressed.png");
}

void MainWindow::on_pushButton_4_released()
{
    butImg(ui->pushButton_4, ":/GameChoice/Assets/money_hover.png");
}

void MainWindow::on_pushButton_3_pressed()
{
    butImg(ui->pushButton_3, ":/GameChoice/Assets/safe_pressed.png");
}

void MainWindow::on_pushButton_3_released()
{
    butImg(ui->pushButton_3, ":/GameChoice/Assets/safe_hover.png");
}

void MainWindow::on_pushButton_4_clicked()
{
    sWindow->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    tWindow->show();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    fWindow->show();
    this->close();
}
