#ifndef BUTTONHOVERWATCHER_H
#define BUTTONHOVERWATCHER_H

#include <QObject>
#include <QPushButton>
#include <QEvent>

class ButtonHoverWatcher : public QObject
{
    Q_OBJECT
    QString Img;
public:
    explicit ButtonHoverWatcher(QObject * parent = Q_NULLPTR, QString img = "");

    virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;
};

#endif // BUTTONHOVERWATCHER_H
