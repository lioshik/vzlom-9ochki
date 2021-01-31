#include "dialog.h"
#include <QTimer>

Dialog::Dialog( QWidget* parent ) : QDialog( parent ) {

    setWindowFlags(Qt::WindowStaysOnTopHint);
    setWindowTitle("Внимание");
    QGridLayout *grid = new QGridLayout();
    message = new QLabel();
    message->setText(texts[rand() % texts.size()].c_str());
    QPushButton* okBtn1 = new QPushButton( "Oк" );
    QPushButton* okBtn2 = new QPushButton( "Да" );
    QPushButton* okBtn3 = new QPushButton( "Продолжить" );
    connect( okBtn1, SIGNAL( clicked() ), SLOT( accept() ) );
    connect( okBtn2, SIGNAL( clicked() ), SLOT( accept() ) );
    connect( okBtn3, SIGNAL( clicked() ), SLOT( accept() ) );

    grid->addWidget(message, 0, 0, 1, 3, Qt::AlignHCenter);
    grid->addWidget(okBtn1, 1, 0);
    grid->addWidget(okBtn2, 1, 1);
    grid->addWidget(okBtn3, 1, 2);
    setLayout(grid);
    show();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(openNew()));
    timer->start(15000);
}

std::vector<std::string> Dialog::texts = {
    "Крым наш",
    "Нагорный Карабах - федеральный округ России",
    "Путин - президент мира",
    "Идёт майнинг Российских криптовалют",
    "Началась миротворческая операция на Донбассе",
    "Доллар по 200",
    "Путин запретил короновирус",
    "В школах ввели обязательные уроки патриотизма",
    "На митингах задержали 32 тыс. человек. Попытка гос. переворота не удалась",
    "Русские вперёд",
    "Выборы в США взломаны на 77%, продолжить?",
    "По данным ВЦИОМ Путина поддерживают 141% россиян",
    "Навального опустили из тюрьмы"
};

void Dialog::openNew() {
    message->setText(texts[rand() % texts.size()].c_str());
    close();
    showNormal();
}
