#include "cupswindow.h"
#include "ui_cupswindow.h"

int gameChoice[2];
int gamesPlayed = 0, award = 0;

CupsWindow::CupsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CupsWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(
                "background-image:url(:/StartMenu/Assets/bg.png); background-position: center;");

    ui->label_6->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();

    butImg(ui->pushButton, ":/StartMenu/Assets/back.png");
    butImg(ui->pushButton_2, ":/StartMenu/Assets/start_bt.png");
    butImg(ui->pushButton_3, ":/Cups/Assets/choice");
    butImg(ui->pushButton_4, ":/Cups/Assets/choice");
    butImg(ui->pushButton_5, ":/Cups/Assets/choice");
    butImg(ui->pushButton_6, ":/Cups/Assets/choice");
    butImg(ui->pushButton_7, ":/Cups/Assets/choice");
    butImg(ui->pushButton_8, ":/Cups/Assets/choice");

    ButtonHoverWatcher * watcher1 = new ButtonHoverWatcher(this, ":/StartMenu/Assets/back");
    ui->pushButton->installEventFilter(watcher1);
    ButtonHoverWatcher * watcher2 = new ButtonHoverWatcher(this, ":/StartMenu/Assets/start_bt");
    ui->pushButton_2->installEventFilter(watcher2);
    ButtonHoverWatcher * watcher3 = new ButtonHoverWatcher(this, ":/Cups/Assets/choice");
    ui->pushButton_3->installEventFilter(watcher3);
    ui->pushButton_4->installEventFilter(watcher3);
    ui->pushButton_5->installEventFilter(watcher3);
    ui->pushButton_6->installEventFilter(watcher3);
    ui->pushButton_7->installEventFilter(watcher3);
    ui->pushButton_8->installEventFilter(watcher3);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timerAlarm()));
}

CupsWindow::~CupsWindow()
{
    delete ui;
}

void CupsWindow::on_pushButton_clicked()
{
    this->close();
    timer->stop();

    ui->label_6->hide();
    ui->pushButton_2->show();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();

    labGif(ui->label_4, "");
    labGif(ui->label_5, "");

    gameChoice[0] = 0;
    gameChoice[1] = 0;
    gamesPlayed = 0;
    award = 0;

    emit MainWindow();
}

void CupsWindow::on_pushButton_2_clicked()
{
    emit Victory(-150);
    ui->pushButton_2->hide();

    labGif(ui->label_4,":/Cups/Assets/cups_appear_1.gif");
    labGif(ui->label_5,":/Cups/Assets/cups_appear_2.gif");

    timer->start(1600);
    gameChoice[0] = arc4random_uniform(3) + 1;
    gameChoice[1] = arc4random_uniform(3) + 1;
}

void CupsWindow::timerAlarm()
{
    ui->label_6->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();

    timer->stop();
}

void CupsWindow::Result(int victory, QString side)
{
    switch (victory)
    {
        case true:
            if (side == "left")
            {
                labGif(ui->label_4,":/Cups/Assets/victory_left.gif");

                ui->pushButton_3->hide();
                ui->pushButton_4->hide();
                ui->pushButton_5->hide();
            }
            else
            {
                labGif(ui->label_5,":/Cups/Assets/victory_right.gif");
                ui->pushButton_6->hide();
                ui->pushButton_7->hide();
                ui->pushButton_8->hide();
            }

            award += 250;
            break;

        case false:
            if (side == "left")
            {
                labGif(ui->label_4,":/Cups/Assets/loss_left.gif");
                ui->pushButton_3->hide();
                ui->pushButton_4->hide();
                ui->pushButton_5->hide();
            }
            else
            {
                labGif(ui->label_5,":/Cups/Assets/loss_right.gif");
                ui->pushButton_6->hide();
                ui->pushButton_7->hide();
                ui->pushButton_8->hide();
            }

            break;
    }
}

void CupsWindow::finalResult()
{
    if (award > 0)
    {
        QMessageBox victory;
        victory.setText("Поздравляем!");
        victory.setInformativeText("Вы выйграли " + QString::number(award) + "$\n");
        victory.setStandardButtons(QMessageBox::Ok);
        victory.setDefaultButton(QMessageBox::Ok);
        victory.exec();

        emit Victory(award);
    }
    else
    {
        QMessageBox loss;
        loss.setText("Увы!");
        loss.setInformativeText("Вы не угадали где шарик ни разу!\n");
        loss.setStandardButtons(QMessageBox::Ok);
        loss.setDefaultButton(QMessageBox::Ok);
        loss.exec();
    }

    on_pushButton_clicked();
}

void CupsWindow::on_pushButton_pressed()
{
    butImg(ui->pushButton, ":/StartMenu/Assets/back_pressed.png");
}

void CupsWindow::on_pushButton_released()
{
    butImg(ui->pushButton, ":/StartMenu/Assets/back_hover.png");
}

void CupsWindow::on_pushButton_2_pressed()
{
    butImg(ui->pushButton_2, ":/StartMenu/Assets/start_bt_pressed.png");
}

void CupsWindow::on_pushButton_2_released()
{
    butImg(ui->pushButton_2, ":/StartMenu/Assets/start_bt_hover.png");
}

void CupsWindow::on_pushButton_3_clicked()
{
    if (gameChoice[0] == 1)
        Result(true, "left");
    else
        Result(false, "left");

    gamesPlayed++;

    if (gamesPlayed == 2)
        finalResult();
}

void CupsWindow::on_pushButton_4_clicked()
{
    if (gameChoice[0] == 2)
        Result(true, "left");
    else
        Result(false, "left");

    gamesPlayed++;

    if (gamesPlayed == 2)
        finalResult();
}

void CupsWindow::on_pushButton_5_clicked()
{
    if (gameChoice[0] == 3)
        Result(true, "left");
    else
        Result(false, "left");

    gamesPlayed++;

    if (gamesPlayed == 2)
        finalResult();
}

void CupsWindow::on_pushButton_6_clicked()
{
    if (gameChoice[1] == 1)
        Result(true, "right");
    else
        Result(false, "right");

    gamesPlayed++;

    if (gamesPlayed == 2)
        finalResult();
}

void CupsWindow::on_pushButton_7_clicked()
{
    if (gameChoice[1] == 2)
        Result(true, "right");
    else
        Result(false, "right");

    gamesPlayed++;

    if (gamesPlayed == 2)
        finalResult();
}

void CupsWindow::on_pushButton_8_clicked()
{
    if (gameChoice[1] == 3)
        Result(true, "right");
    else
        Result(false, "right");

    gamesPlayed++;

    if (gamesPlayed == 2)
        finalResult();
}
