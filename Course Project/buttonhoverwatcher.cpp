#include "buttonhoverwatcher.h"

ButtonHoverWatcher::ButtonHoverWatcher(QObject * parent, QString img) :
    QObject(parent)
{
    Img = img;
}

bool ButtonHoverWatcher::eventFilter(QObject * watched, QEvent * event)
{
    QPushButton * button = qobject_cast<QPushButton*>(watched);
    if (!button) {
        return false;
    }

    if (event->type() == QEvent::Enter) {
        QString way;
        way = Img + "_hover.png";
        button->setIcon(QIcon(way));
        return true;
    }

    if (event->type() == QEvent::Leave){
        QString way;
        way = Img + ".png";
        button->setIcon(QIcon(way));
        return true;
    }

    return false;
}
