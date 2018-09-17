#include "foomodel.h"
#include <QDebug>
#include <QPointer>

FooModel::FooModel(QObject *parent) : QObject(parent)
{

}

void FooModel::callWithSignalConnect()
{
    Foo *tempFooA = new Foo();
    connect(tempFooA, SIGNAL(fooReply(int)), this, SLOT(handleReplyA(int)));
    tempFooA->asyncWithSignal();

//    Foo *tempFooB = new Foo();
//    connect(tempFooB, SIGNAL(fooReply(int)), this, SLOT(handleReplyB(int)));
//    tempFooB->asyncWithSignal();
}

void FooModel::handleReplyA(int status)
{
    qDebug() << "handleReplyA !!!!!!! result=" << status;
}

void FooModel::handleReplyB(int status)
{
    qDebug() << "handleReplyB !!!!!!! result=" << status;
}

void FooModel::callWithSlot()
{
    m_foo->asyncWithSlot(this, "handleReplyA");
    //m_foo->asyncWithSlot(this, "handleReplyB");
}

void FooModel::callWithLambda()
{
    m_foo->asyncWithLambda(this, [this] (int status) {
            //handleReplyA(result);
            QMetaObject::invokeMethod(this, "handleReplyA", Q_ARG(int, status));
        });

//    m_foo->asyncWithLambda(this, [this] (int status) {
//            //handleReplyB(result);
//            QMetaObject::invokeMethod(this, "handleReplyB", Q_ARG(int, status));
//        });
}

