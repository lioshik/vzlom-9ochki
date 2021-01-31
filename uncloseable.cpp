#include "uncloseable.h"
#include <QCloseEvent>
#include <QTimer>
#include <QLabel>
#include <QMovie>
#include <string>
#include <QString>
#include <vector>


Uncloseable::Uncloseable(QWidget *parent) : QMainWindow(parent)
{
    //setAttribute(Qt::WA_NoSystemBackground, true);
    //setAttribute(Qt::WA_TranslucentBackground, true);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowTitleHint);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(reOpen()));
    timer->start(2500);
}

std::vector<std::string> Uncloseable::images1 = {
    "putin1.gif",
    "putin2.gif",
    "putin3.jpeg",
    "putin4.gif",
    "putin5.gif",
    "putin6.gif",
    "putin7.gif",
    "putin8.jpeg",
    "putin9.jpg",
    "putin10.jpg",
    "putin11.jpeg"
    };

void Uncloseable::changeImage() {
    bool again = true;
    if (this->centralWidget()) {
        delete (this->centralWidget());
        again = false;
    }
    int i = rand() % images1.size();
    QLabel *lbl = new QLabel();
    auto newPath = QString(":/gifs/");
    newPath.append(images1[i].c_str());
    QMovie* movie = new QMovie(newPath);
    lbl->setMovie(movie);
    lbl->setScaledContents(true);
    setCentralWidget(lbl);
    movie->start();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeImage()));
    if (again) timer->start(2000);
}

void Uncloseable::reOpen() {
    this->hide();
    this->showMaximized();
}

void Uncloseable::closeEvent(QCloseEvent *event) {
    event->ignore();
}
