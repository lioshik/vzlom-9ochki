#ifndef BARCHANGER_H
#define BARCHANGER_H
#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>

class BarChanger : public QProgressBar
{
    Q_OBJECT
public slots:
    void changeBar();
public:
    explicit BarChanger(QWidget *parent = nullptr);
private:
    QTimer *timer;
};

#endif // BARCHANGER_H
