#ifndef TESTPAGE_H
#define TESTPAGE_H

#include <QWidget>
#include <QQuickWidget>
#include <QStackedLayout>
#include <QQuickView>
#include <QTimer>

class TestPage : public QWidget
{
    Q_OBJECT
public:
    explicit TestPage(QWidget *parent = nullptr);
    ~TestPage();

private:
    QQuickWidget *qquickWidget;
    QStackedLayout *l;
    QQuickView *quickview;

signals:

public slots:
};

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0) : QWidget(parent) {
        widget = 0;
        count = 0;
        resize(200, 200);
        layout = new QVBoxLayout(this);
        setLayout(layout);
        QTimer * t = new QTimer(this);
        t->setInterval(200);
        t->setSingleShot(false);
        t->start();
        connect (t, SIGNAL(timeout()), this, SLOT(toggleQuickView()));
    }

public slots:
    void toggleQuickView() {
        if (!widget) {
            widget = new QQuickWidget;
            widget->setSource(QUrl("qrc:/test.qml"));
            connect(widget, SIGNAL(destroyed()), this, SLOT(echo()));
            layout->addWidget(widget);
        } else {
            layout->removeWidget(widget);
            widget->deleteLater();
            widget = 0;
        }
    }

    void echo() {
        qDebug() << "this is a test";
        //PROCESS_MEMORY_COUNTERS memcount;
        //if (!GetProcessMemoryInfo(GetCurrentProcess(), &memcount, sizeof(memcount))) return;
        //qDebug() << ++count << "created and destroyed," << memcount.WorkingSetSize / (1024 * 1024) << "MB memory used";
    }

private:
    QVBoxLayout * layout;
    QQuickWidget * widget;
    int count;
};

#endif // TESTPAGE_H
