#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QRandomGenerator>
#include <QHBoxLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void updateShit();
    QHBoxLayout *layout = new QHBoxLayout();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void shitPressed();

private:
    Ui::MainWindow *ui;
    QTimer *_trShit = nullptr;
    QPushButton *_shitButton = nullptr;
    double _intervalShit;
    QRandomGenerator randomGenShit;
    int score{0};
    int shitW{150};
    int shitH{150};
};
#endif // MAINWINDOW_H
