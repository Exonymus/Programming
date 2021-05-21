#include "moneywindow.h"
#include "ui_moneywindow.h"

QString code = "";

MoneyWindow::MoneyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MoneyWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(
                "background-image:url(:/StartMenu/Assets/bg.png); background-position: center;");

    butImg(ui->pushButton, ":/StartMenu/Assets/back.png");
    butImg(ui->pushButton_2, ":/Money/Assets/cd_gen.png");
    butImg(ui->pushButton_3, ":/Money/Assets/cd_enter.png");

    ButtonHoverWatcher * watcher1 = new ButtonHoverWatcher(this, ":/StartMenu/Assets/back");
    ui->pushButton->installEventFilter(watcher1);
    ButtonHoverWatcher * watcher2 = new ButtonHoverWatcher(this, ":/Money/Assets/cd_gen");
    ui->pushButton_2->installEventFilter(watcher2);
    ButtonHoverWatcher * watcher3 = new ButtonHoverWatcher(this, ":/Money/Assets/cd_enter");
    ui->pushButton_3->installEventFilter(watcher3);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerAlarm()));
}

MoneyWindow::~MoneyWindow()
{
    delete ui;
}

void MoneyWindow::on_pushButton_clicked()
{
    this->close();
    timer->stop();
    ui->label->hide();
    ui->pushButton_2->setEnabled(true);
    ui->pushButton_3->setEnabled(false);
    ui->textEdit->setText("");
    ui->textBrowser->setText("");
    ui->label->hide();
    code = "";
    emit MainWindow();
}

void MoneyWindow::on_pushButton_2_clicked()
{
    ui->label->show();
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(true);

    labGif(ui->label, ":/Money/Assets/timer.gif");
    timer->start(20000);

    for (int i = 0; i < 25; i++)
        code += QString::number(arc4random() % 10);

    ui->textBrowser->setText(code);
    ui->textBrowser->setAlignment(Qt::AlignCenter);
}

void MoneyWindow::timerAlarm()
{
    ui->label->hide();
    QMessageBox loss;
    loss.setText("Не повезло, не повезло...");
    loss.setInformativeText("Вы не успели ввести код!\n");
    loss.setStandardButtons(QMessageBox::Ok);
    loss.setDefaultButton(QMessageBox::Ok);
    loss.exec();

    on_pushButton_clicked();
}

void MoneyWindow::on_pushButton_3_clicked()
{
    if (code == ui->textEdit->toPlainText())
    {
        timer->stop();
        ui->label->hide();

        QMessageBox victory;
        victory.setText("Поздравляем!");
        victory.setInformativeText("Вы ввели правильный код и выйграли 100$\n");
        victory.setStandardButtons(QMessageBox::Ok);
        victory.setDefaultButton(QMessageBox::Ok);
        victory.exec();

        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
        ui->textEdit->setText("");
        ui->textBrowser->setText("");
        ui->label->hide();
        code = "";
        this->close();
        emit Victory(100);
        emit MainWindow();
    }
    else
    {
        QMessageBox incorrect;
        incorrect.setText("Код неверен!");
        incorrect.setInformativeText("Попробуйте еще раз!\n");
        incorrect.setStandardButtons(QMessageBox::Ok);
        incorrect.setDefaultButton(QMessageBox::Ok);
        incorrect.exec();
    }
}

void MoneyWindow::on_pushButton_pressed()
{
   butImg(ui->pushButton, ":/StartMenu/Assets/back_pressed.png");
}

void MoneyWindow::on_pushButton_released()
{
    butImg(ui->pushButton, ":/StartMenu/Assets/back_hover.png");
}

void MoneyWindow::on_pushButton_2_pressed()
{
    butImg(ui->pushButton_2, ":Money/Assets/cd_gen_pressed.png");
}

void MoneyWindow::on_pushButton_2_released()
{
   butImg(ui->pushButton_2, ":Money/Assets/cd_gen_hover.png");
}

void MoneyWindow::on_pushButton_3_pressed()
{
    butImg(ui->pushButton_3, ":/Money/Assets/cd_enter_pressed.png");
}

void MoneyWindow::on_pushButton_3_released()
{
    butImg(ui->pushButton_3, ":/Money/Assets/cd_enter_hover");
}
