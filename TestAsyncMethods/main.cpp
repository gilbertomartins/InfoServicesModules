#include "mainwindow.h"
#include <QApplication>
#include "foomodel.h"
#include "foo.h"
#include "QDebug"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    FooModel *model = new FooModel(&w);

    Foo *emitter = new Foo(&w);

    model->setFoo(emitter);

    model->callWithSlot();

    model->callWithLambda();

    model->callWithSignalConnect();

    // delete the model
    //delete model;

    return a.exec();
}
