#ifndef UNCLOSEABLE_H
#define UNCLOSEABLE_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QMovie>

class Uncloseable : public QMainWindow
{
    Q_OBJECT
public:
    static std::vector<std::string> images1;
    explicit Uncloseable(QWidget *parent = nullptr);
    void startChanging();

public slots:
    void changeImage();
    void reOpen();

private:
    void closeEvent(QCloseEvent *);
    QMovie *movie = nullptr;
signals:

};

#endif // UNCLOSEABLE_H
