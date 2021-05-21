#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QPushButton>
#include <QMessageBox>
#include <QPixmap>
#include <QString>
#include <QTimer>
#include <QLabel>
#include <QMovie>

void butImg(QPushButton * b, QString way);
void labImg(QLabel * l, QString way);
void labGif(QLabel * l, QString way);
void buttonPress(QPushButton * b, bool press);

#endif // GRAPHICS_H
