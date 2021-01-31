#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <string>

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog( QWidget* parent = 0 );
    static std::vector<std::string> texts;

    QString getInput() const;

signals:
    void applied();
public slots:
    void openNew();

private:
    QLabel *message;

};


#endif // DIALOG_H
