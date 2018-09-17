#include "module2mock.h"

#include <QDebug>

Module2Mock::Module2Mock(QObject *parent) : Module2(parent)
{

}

void Module2Mock::bar()
{
    qDebug() << "Class Module2 MOCK: Execute method bar";
}
