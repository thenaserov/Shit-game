#include "mainwindow.h"
#include "ui_mainwindow.h"
// A shitty game coded by Naser Rezayi
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    _shitButton = new QPushButton(this);
    _shitButton->resize(shitW, shitH);
    _shitButton->setStyleSheet("boarder : 1px;");
    _trShit = new QTimer();
    _intervalShit = 1000;
    _trShit->setInterval(_intervalShit);
    connect(_trShit, &QTimer::timeout, this, &MainWindow::updateShit); // A shitty game coded by Naser Rezayi
    connect(_shitButton, &QPushButton::clicked, this, &MainWindow::shitPressed);
    QPixmap pm = QPixmap(":/kindshit.png");
}

void MainWindow::updateShit()
{
    QPixmap pm = QPixmap(":/kindshit.png");
    this->rect().topLeft().rx();
    int x1 = randomGenShit.bounded(ui->gameWidget->rect().topLeft().rx(), ui->gameWidget->rect().bottomRight().rx());
    int y1 = randomGenShit.bounded(ui->gameWidget->rect().topLeft().ry(), ui->gameWidget->rect().bottomRight().ry());
    _shitButton->setIcon(QIcon(pm.scaled(_shitButton->width(), _shitButton->height(), Qt::KeepAspectRatio)));
    _shitButton->setIconSize(pm.rect().size());
    _shitButton->move(x1, y1);
    _intervalShit-=1;
    _trShit->setInterval(_intervalShit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    _trShit->start();
   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->~MainWindow();
}

void MainWindow::shitPressed()
{
    QPixmap pm = QPixmap(":/kind.png");
    _shitButton->setIcon(QIcon(pm.scaled(_shitButton->width(), _shitButton->height(), Qt::KeepAspectRatio)));
    _shitButton->setIconSize(pm.rect().size());
    if (_intervalShit > 500)
    {
        _intervalShit-=10;
        score += 1;
        ui->label_3->setText("Score : " + QString::number(score));
    }
    else if (_intervalShit > 100)
    {
        _intervalShit-=1;
        score += 1;
        ui->label_3->setText("Score : " + QString::number(score));
    }
    else if(_intervalShit>=5)
    {
        _intervalShit-=1;
        score += 1;
        ui->label_3->setText("Score : " + QString::number(score));
    }
}
