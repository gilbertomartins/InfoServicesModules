#ifndef MODULE1_H
#define MODULE1_H

#include <QObject>

#include "infoservicesmodule.h"

class Module2;

class Module1 : public QObject, public InfoServicesModule
{
    Q_OBJECT
public:
    explicit Module1(QObject *parent = 0);
    virtual ~Module1();


    virtual void init();
    virtual void start() {}

    void foo();

    void bar();

private:
    Module2 *m_module2;
};

#endif // MODULE1_H
