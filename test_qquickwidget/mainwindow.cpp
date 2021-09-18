#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>
#include <QQuickWidget>
#include <QQuickItem>
#include <testpage.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(200);
    timer->setSingleShot(false);

    //test code,open&destroy widget in timer.
    connect (timer, SIGNAL(timeout()), this, SLOT(toggleQuickWidget()));
    timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cancelBtn_clicked(){
    close();
}

void MainWindow::on_okBtn_clicked(){
    qDebug() << "ok btn clicked";
    TestPage *testPage = new TestPage();
    testPage->show();
}

void MainWindow::toggleQuickWidget() {
    static int count = 0;
    count ++;
    qDebug() << count;
    TestPage *testPage = new TestPage();
    testPage->show();
    testPage->close();
    testPage->deleteLater();

    if (count > 500) {
        timer->stop();
    }
}

