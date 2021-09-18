#include "testpage.h"

#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QQmlProperty>

TestPage::TestPage(QWidget *parent) : QWidget(parent)
{
    qquickWidget = nullptr;
    quickview = nullptr;

    qquickWidget = new QQuickWidget(this);
    qquickWidget->setSource(QUrl("qrc:/test.qml"));
    qquickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    l = new QStackedLayout(this);
    l->addWidget(qquickWidget);
    this->setLayout(l);

    //there is no memory leak when use QQuickView and createWindowContainer
//    quickview = new QQuickView();
//    QWidget *container = QWidget::createWindowContainer(quickview, this);
//    container->setMinimumSize(400, 400);
//    container->setMaximumSize(400, 400);
//    quickview->setSource(QUrl("qrc:/test.qml"));
//    //embedded qquickview to qwidget
//    l = new QStackedLayout(this);
//    l->addWidget(container);
//    this->setLayout(l);
}

TestPage::~TestPage() {
    qDebug() << "destroy TestPage...";

    if (qquickWidget) {
        //qquickWidget->engine()->clearComponentCache();
        delete qquickWidget;
        qquickWidget = nullptr;
    }

    if (quickview) {
        delete quickview;
        quickview = nullptr;
    }

//    if (l) {
//        delete l;
//        l = nullptr;
//    }
}
