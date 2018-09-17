#ifndef FOOMODEL_H
#define FOOMODEL_H

#include <QObject>
#include "foo.h"

class FooModel : public QObject
{
    Q_OBJECT
public:
    explicit FooModel(QObject *parent = 0);

    void setFoo(Foo *foo) {
        m_foo = foo;
    }

    void callWithSlot();

    void callWithLambda();

    void callWithSignalConnect();

private:
    Foo *m_foo;

public slots:
    void handleReplyA(int status);
    void handleReplyB(int status);
};

#endif // CUSTOMOJB_H
