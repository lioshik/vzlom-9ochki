#ifndef UNCLOSEABLE_H
#define UNCLOSEABLE_H

#include <QMainWindow>
#include <string>
#include <vector>

class Uncloseable : public QMainWindow
{
    Q_OBJECT
public:
    static std::vector<std::string> images1;
    explicit Uncloseable(QWidget *parent = nullptr);

public slots:
    void changeImage();
    void reOpen();

private:
    void closeEvent(QCloseEvent *);

signals:

};

#endif // UNCLOSEABLE_H
