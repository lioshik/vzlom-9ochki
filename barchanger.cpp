#include "barchanger.h"
#include <QCloseEvent>
#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QMovie>
#include <string>
#include <QString>
#include <vector>

BarChanger::BarChanger(QWidget *parent) : QProgressBar(parent) {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeBar()));
    timer->start(8);
    setMaximum(100);
    setValue(0);
}
void BarChanger::changeBar() {
    setValue((value() + 1) % 100);
    timer->stop();
    int crt = timer->interval();
    if (value() == 0) {
        crt = rand() % 40 + 1;
    }
    timer->start(crt);
}
