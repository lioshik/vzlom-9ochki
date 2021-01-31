#include <QApplication>
#include <QWidget>
#include <QCloseEvent>
#include <QMainWindow>
#include <QLabel>
#include <QMovie>
#include <QDir>
#include <QRect>
#include <QDesktopWidget>
#include "uncloseable.h"
#include <QGridLayout>
#include <QProgressBar>
#include <QWidget>
#include <QTimer>
#include <barchanger.h>
#include <dialog.h>

void changeBar(QProgressBar* bar) {
    int crv = bar->value();
    int nv = (crv + 1) % 100;
    bar->setValue(nv);
}

int main(int argc, char *argv[])
{
    // --------------------------
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    // --------------------------


    // Putin
    Uncloseable windowPutin;
    int screenH = QApplication::desktop()->geometry().height();
    int screenW = QApplication::desktop()->geometry().width();
    windowPutin.setAttribute(Qt::WA_NoSystemBackground, true);
    windowPutin.setAttribute(Qt::WA_TranslucentBackground, true);
    windowPutin.setFixedSize(screenW / 5.5, screenH / 4);
    windowPutin.move(screenW - windowPutin.width() * 1.8, screenH - windowPutin.height() * 1.8);
    windowPutin.setWindowTitle("кибератака на США");
    windowPutin.show();
    windowPutin.changeImage();

    // Vzlom
    Uncloseable windowVzlom;
    QWidget *gridWidget = new QWidget();
    auto palette = gridWidget->palette();
    palette.setColor(QPalette::Background, Qt::blue);
    windowVzlom.setPalette(palette);
    QVBoxLayout *gridLayout = new QVBoxLayout(gridWidget);
    QLabel *lblVzlom = new QLabel();
    lblVzlom->setText("Взлом госучереждений США");
    QFont f( "Arial", 14, QFont::Bold);
    lblVzlom->setFont(f);
    BarChanger *vzlomBar = new BarChanger();

    gridLayout->addWidget(lblVzlom, Qt::AlignmentFlag::AlignHCenter);
    gridLayout->addWidget(vzlomBar, Qt::AlignmentFlag::AlignHCenter);
    windowVzlom.setCentralWidget(gridWidget);

    windowVzlom.setFixedSize(screenW / 4, screenH / 6);
    windowVzlom.move(windowVzlom.width() * 0.5, screenH - windowVzlom.height() * 1.8);
    windowVzlom.show();
    vzlomBar->setMaximum(100);
    palette.setColor(QPalette::Highlight, Qt::darkGreen);
    vzlomBar->setPalette(palette);
    windowVzlom.setWindowTitle("кибератака на США");


    Dialog *dialog = new Dialog();
    Uncloseable windowImage;
    QLabel *img = new QLabel();
    img->setScaledContents(true);
    img->setPixmap(QPixmap(":/gifs/lioshik.jpg"));
    windowImage.setCentralWidget(img);
    windowImage.setFixedSize(220, 220);
    windowImage.move(screenW - windowImage.width() * 1.2, windowImage.height() * 0.2);
    windowImage.show();
    return a.exec();
}
