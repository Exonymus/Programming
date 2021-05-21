#include "graphics.h"

void butImg(QPushButton * b, QString way)
{
    QPixmap pixmap(way);
    QIcon ButtonIcon(pixmap);
    b->setIcon(ButtonIcon);
    b->setIconSize(pixmap.rect().size());

}

void labImg(QLabel * l, QString way)
{
    QPixmap pixmap(way);
    l->setPixmap(pixmap);
    l->setMask(pixmap.mask());

}
void labGif(QLabel *l, QString way)
{
    if (way == "")
    {
        l->clear();
        return;
    }

    QMovie *movie = new QMovie(way);
    l->setMovie(movie);
    movie->start();
    l->setStyleSheet("background: transparent;");
}

void buttonPress(QPushButton* b, bool press)
{
    if (press)
        b->setStyleSheet(
                        "color: #000000;"
                        "border: 2px solid black;"
                        "border-radius: 4px;"
                        "padding: -1px;"
                        "background: rgb(198, 196, 199);");
    else
        b->setStyleSheet(
                        "color: #000000;"
                        "border: 2px solid black;"
                        "border-radius: 4px;"
                        "padding: -1px;"
                        "background: #FFFFFF");
}



