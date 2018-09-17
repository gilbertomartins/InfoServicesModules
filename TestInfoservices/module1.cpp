#include "module1.h"

#include <QDebug>

#include "infoservices.h"
#include "module2.h"

Module1::Module1(QObject *parent) : QObject(parent)
{

}

Module1::~Module1()
{
    qDebug() << "Destroying module 11111111";
}

void Module1::init()
{
    // In the init method you can access any module, even those
    // who were created after this instance.
    Module2 *module2 = InfoServices::get<Module2>();
    module2->bar();

    m_module2 = module2;
}

void Module1::foo()
{
    qDebug() << "Execute method foo!";
}

void Module1::bar()
{
    qDebug() << "CLASS Module1 will call method bar() from class Module2!";
    m_module2->bar();
}
