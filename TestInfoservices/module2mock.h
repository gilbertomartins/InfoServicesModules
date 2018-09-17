#ifndef MODULE2MOCK_H
#define MODULE2MOCK_H

#include <QObject>

#include "module2.h"

class Module2Mock : public Module2
{
    Q_OBJECT
public:
    explicit Module2Mock(QObject *parent = 0);

    void bar();
};

#endif // MODULE2MOCK_H
