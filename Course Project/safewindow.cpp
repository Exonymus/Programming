#include "safewindow.h"
#include "ui_safewindow.h"

int safeCode;
int tries = 3;
QString strCode = "";
QString userCode = "";
QString knownCode = "_ _ _";

SafeWindow::SafeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SafeWindow)
{
    ui->setupUi(this);
    this->centralWidget()->setStyleSheet(
                "background-image:url(:/StartMenu/Assets/bg.png); background-position: center;");

    ui->label_5->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->label_2->setAlignment(Qt::AlignCenter);

    butImg(ui->pushButton, ":/StartMenu/Assets/back.png");
    butImg(ui->pushButton_12, ":/StartMenu/Assets/start_bt.png");

    ButtonHoverWatcher * watcher1 = new ButtonHoverWatcher(this, ":/StartMenu/Assets/back");
    ui->pushButton->installEventFilter(watcher1);
    ButtonHoverWatcher * watcher2 = new ButtonHoverWatcher(this, ":/StartMenu/Assets/start_bt");
    ui->pushButton_12->installEventFilter(watcher2);
}

SafeWindow::~SafeWindow()
{
    delete ui;
}

void SafeWindow::on_pushButton_clicked()
{
    ui->pushButton_12->show();
    ui->label_5->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->textBrowser->clear();
    ui->label_6->setStyleSheet("image: url(:/Safe/Assets/tries3.png); background: transparent;");
    ui->label_2->setText("_ _ _");

    tries = 3;
    safeCode  = 0;
    strCode.clear();
    userCode.clear();
    knownCode = "_ _ _";

    this->close();
    emit MainWindow();
}

void SafeWindow::on_pushButton_pressed()
{
   butImg(ui->pushButton, ":/StartMenu/Assets/back_pressed.png");
}

void SafeWindow::on_pushButton_released()
{
    butImg(ui->pushButton, ":/StartMenu/Assets/back_hover.png");
}

void SafeWindow::on_pushButton_12_pressed()
{
    butImg(ui->pushButton_12, ":/StartMenu/Assets/start_bt_pressed.png");
}

void SafeWindow::on_pushButton_12_released()
{
    butImg(ui->pushButton_12, ":/StartMenu/Assets/start_bt_hover.png");
}

void SafeWindow::on_pushButton_12_clicked()
{
    emit Victory(-350);
    ui->pushButton_12->hide();
    ui->label_5->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->pushButton_9->show();
    ui->pushButton_10->show();
    ui->pushButton_11->show();

    bool check = false;
    int code_1 = 0, code_2 = 0, code_3 = 0;

    while (!check)
    {
        safeCode = arc4random_uniform(899) + 100;

        code_1 = safeCode / 100;
        code_2 = safeCode / 10 % 10;
        code_3 = safeCode % 10;

        if ((code_1 != code_2) && (code_2 != code_3) && (code_1 != code_3))
            check = true;
        if ((code_1 * code_2 * code_3) == 0)
            check = false;
    }

    ui->textBrowser->setText("Код Сгенерирован!");
    ui->textBrowser->setAlignment(Qt::AlignCenter);
    ui->textBrowser->append("У вас " + QString::number(tries) + " попытки подобрать числа последовательности:");

    strCode = QString::number(safeCode);
}

void SafeWindow::on_pushButton_2_clicked()
{
    if (tries > 0)
    {
        ui->textBrowser->append(QString::number(4 - tries) + " попытка: " + userCode);
        tries--;
        if (tries)
            ui->label_6->setStyleSheet("image: url(:/Safe/Assets/tries" + QString::number(tries) + ".png); background: transparent;");

        QChar ch1 = userCode[0];
        QChar ch2 = userCode[1];
        QChar ch3 = userCode[2];
        QChar code_1 = strCode[0];
        QChar code_2 = strCode[1];
        QChar code_3 = strCode[2];

        if (((ch1 == code_1) && (ch2 == code_2) && (ch3 == code_3)) ||
            ((ch1 == code_2) && (ch2 == code_1) && (ch3 == code_3)) ||
            ((ch1 == code_3) && (ch2 == code_2) && (ch3 == code_1)) ||
            ((ch1 == code_1) && (ch2 == code_3) && (ch3 == code_2)) ||
            ((ch1 == code_3) && (ch2 == code_1) && (ch3 == code_2)) ||
            ((ch1 == code_2) && (ch2 == code_3) && (ch3 == code_1)))
        {
            Open(code_1);
            Open(code_2);
            Open(code_3);

            QMessageBox victory;
            int award = arc4random() % 350 + 750;
            victory.setText("Поздравляем!");
            victory.setInformativeText("Вы подобрали код к сейфу!\nВаш выгрыш составил:"+QString::number(award)+"$!\n");
            victory.setStandardButtons(QMessageBox::Ok);
            victory.setDefaultButton(QMessageBox::Ok);
            victory.exec();

            on_pushButton_clicked();
            emit Victory(award);
            return;
        }
        else if (!tries)
        {
            Loss();
            return;
        }

        QChar check[3] {ch1, ch2, ch3};
        bool found = false;

        for (int k = 0; k < 3; k++)
        {
            if (code_1 == check[k])
            {
                ui->textBrowser->append("\n" + QString::number(k + 1) + " цифра в коде есть!");
                found = true;
            }
            if (found)
            {
                Open(code_1);
                found = false;
            }

            if (code_2 == check[k])
            {
                ui->textBrowser->append("\n" + QString::number(k + 1) + " цифра в коде есть!");
                found = true;
            }
            if (found)
            {
                Open(code_2);
                found = false;
            }

            if (code_3 == check[k])
            {
                ui->textBrowser->append("\n" + QString::number(k + 1) + " цифра в коде есть!");
                found = true;
            }
            if (found)
            {
                Open(code_3);
                found = false;
            }
        }

        userCode = "";
        ui->pushButton_2->hide();
    }
    else
        Loss();

}

void SafeWindow::Open(QChar ch)
{
    int i = 0;
    while (strCode[i] != ch)
        i++;

    switch(i)
    {
        case 0:
            knownCode[0] = ch;
            break;
        case 1:
            knownCode[2] = ch;
            break;
        case 2:
            knownCode[4] = ch;
            break;
    }

    ui->label_2->setText(knownCode);
}

void SafeWindow::Loss()
{
    QMessageBox loss;
    loss.setText("Не повезло, не повезло...");
    loss.setInformativeText("Вы не смогли подобрать код от сейфа!\n"
                            "Код был: " + QString::number(safeCode));
    loss.setStandardButtons(QMessageBox::Ok);
    loss.setDefaultButton(QMessageBox::Ok);
    loss.exec();

    on_pushButton_clicked();
}

void SafeWindow::on_pushButton_3_clicked()
{
    if (userCode.length() != 3)
        userCode.append("1");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_4_clicked()
{
    if (userCode.length() != 3)
        userCode.append("4");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_5_clicked()
{
    if (userCode.length() != 3)
        userCode.append("7");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_6_clicked()
{
    if (userCode.length() != 3)
        userCode.append("5");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_7_clicked()
{
    if (userCode.length() != 3)
        userCode.append("8");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_8_clicked()
{
    if (userCode.length() != 3)
        userCode.append("2");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_9_clicked()
{
    if (userCode.length() != 3)
        userCode.append("6");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_10_clicked()
{
    if (userCode.length() != 3)
        userCode.append("9");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_11_clicked()
{
    if (userCode.length() != 3)
        userCode.append("3");
    else
        ui->pushButton_2->show();

    if (userCode.length() == 3)
        ui->pushButton_2->show();
}

void SafeWindow::on_pushButton_2_pressed()
{
    buttonPress(ui->pushButton_2, true);
}

void SafeWindow::on_pushButton_2_released()
{
    buttonPress(ui->pushButton_2, false);
}

void SafeWindow::on_pushButton_3_pressed()
{
    buttonPress(ui->pushButton_3, true);
}

void SafeWindow::on_pushButton_3_released()
{
    buttonPress(ui->pushButton_3, false);
}

void SafeWindow::on_pushButton_4_pressed()
{
    buttonPress(ui->pushButton_4, true);
}

void SafeWindow::on_pushButton_4_released()
{
    buttonPress(ui->pushButton_4, false);
}

void SafeWindow::on_pushButton_5_pressed()
{
    buttonPress(ui->pushButton_5, true);
}

void SafeWindow::on_pushButton_5_released()
{
    buttonPress(ui->pushButton_5, false);
}

void SafeWindow::on_pushButton_6_pressed()
{
    buttonPress(ui->pushButton_6, true);
}

void SafeWindow::on_pushButton_6_released()
{
    buttonPress(ui->pushButton_6, false);
}

void SafeWindow::on_pushButton_7_pressed()
{
    buttonPress(ui->pushButton_7, true);
}

void SafeWindow::on_pushButton_7_released()
{
    buttonPress(ui->pushButton_7, false);
}

void SafeWindow::on_pushButton_8_pressed()
{
    buttonPress(ui->pushButton_8, true);
}

void SafeWindow::on_pushButton_8_released()
{
    buttonPress(ui->pushButton_8, false);
}

void SafeWindow::on_pushButton_9_pressed()
{
    buttonPress(ui->pushButton_9, true);
}

void SafeWindow::on_pushButton_9_released()
{
    buttonPress(ui->pushButton_9, false);
}

void SafeWindow::on_pushButton_10_pressed()
{
    buttonPress(ui->pushButton_10, true);
}

void SafeWindow::on_pushButton_10_released()
{
    buttonPress(ui->pushButton_10, false);
}

void SafeWindow::on_pushButton_11_pressed()
{
    buttonPress(ui->pushButton_11, true);
}

void SafeWindow::on_pushButton_11_released()
{
    buttonPress(ui->pushButton_11, false);
}
