#include "module2.h"

#include <QDebug>

#include "infoservices.h"
#include "module1.h"

Module2::Module2(QObject *parent) : QObject(parent)
{
}

Module2::~Module2()
{
    qDebug() << "Destroying module 2222222";
}

void Module2::init()
{
}

void Module2::bar()
{
    qDebug() << "Class Module2: Execute method bar";
}
