#include "foo.h"
#include <QTimer>
#include <QDebug>
#include "foomodel.h"

Foo::Foo(QObject *parent) : QObject(parent)
{
}

Foo::~Foo() {
    qDebug() << "Destroying Foo !!!!!!!!!!!!!!!!!!";
}

void Foo::asyncWithSlot(QObject *caller, const char * slot)
{
    QPointer<QObject> p = caller;
    m_obj = p;
    m_slot = slot;
    QTimer::singleShot(1000, this, SLOT(onTimeoutSlot()));
}

void Foo::asyncWithLambda(QObject *caller, FooCallback callback)
{
    QPointer<QObject> p = caller;
    m_callback = callback;
    QTimer::singleShot(2000, this, SLOT(onTimeoutLambda()));
}

void Foo::onTimeoutSlot()
{
    if (m_obj) {
        qDebug() << "Obj is alive!!!! call SLOT=" << m_slot;
        QMetaObject::invokeMethod(m_obj, m_slot.toStdString().c_str(), Q_ARG(int, 1));
    } else {
        qDebug() << "Obj is DEAD!!!!";
    }
}

void Foo::onTimeoutLambda()
{
    if (m_obj) {
        qDebug() << "Obj is alive!!!! Call LAMBDA";
        m_callback(1);
    } else {
        qDebug() << "Obj is DEAD!!!!";
    }
}

void Foo::asyncWithSignal()
{
    connect(this, SIGNAL(fooReply(int)), this, SLOT(deleteLater()));
    QTimer::singleShot(3000, this, SLOT(onTimeoutSignal()));
}

void Foo::onTimeoutSignal()
{
    qDebug() << "Emitting signal!!!!";
    emit fooReply(1);
}
