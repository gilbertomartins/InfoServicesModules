#include "mainwindow.h"
#include <QApplication>

#include "infoservices.h"

#include "module1.h"
#include "module2.h"
#include "module2mock.h"

void run() {
    InfoServices::init();

    // Here we can connect to any signal before start threads, timers and state machines.
    // ...

    InfoServices::start();

    Module1 *module1 = InfoServices::get<Module1>();
    module1->foo();
}


void test() {

    QCoreApplication *parent = QCoreApplication::instance();

    // Inject Module2Mock
    InfoServices::set<Module2>(new Module2Mock(parent));

    Module1 *module1 = new Module1(parent);
    module1->init();

    // Now we can test method foo.
    module1->foo();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    run();
    test();
    return a.exec();
}
