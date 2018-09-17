#ifndef MODULE2_H
#define MODULE2_H

#include <QObject>

#include "infoservicesmodule.h"

class Module2 : public QObject , public InfoServicesModule
{
    Q_OBJECT
public:
    explicit Module2(QObject *parent = 0);
    virtual ~Module2();

    virtual void init();
    void start() {}

    virtual void bar();
};

#endif // MODULE2_H
