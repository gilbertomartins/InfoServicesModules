#include "infoservices.h"

#include <QCoreApplication>

#include "infoservicesmodule.h"

#include "module1.h"
#include "module2.h"

QMap<const std::type_info*, InfoServicesModule*> InfoServices::s_modules = QMap<const std::type_info*, InfoServicesModule*>();

void InfoServices::addModule(InfoServicesModule* module)
{
    s_modules[&typeid(*module)] = module;
}

void InfoServices::init()
{
    QCoreApplication *app = QCoreApplication::instance();
    Q_ASSERT(app);

    Module1 *module1 = new Module1(app);
    addModule(module1);

    Module2 *module2 = new Module2(app);
    addModule(module2);

    foreach(InfoServicesModule* module, s_modules.values()) {
        module->init();
    }
}

void InfoServices::start()
{
    foreach(InfoServicesModule* module, s_modules.values()) {
        module->start();
    }
}
