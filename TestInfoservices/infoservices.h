#ifndef INFOSERVICES_H
#define INFOSERVICES_H

#include <QMap>
#include <typeinfo>
#include <QDebug>

class InfoServicesModule;

class InfoServices
{
public:
    static void init();
    static void start();

    template <typename T>
    static T* get()
    {
        if(s_modules.contains(&typeid(T))) {
            return static_cast<T*>(s_modules[&typeid(T)]);
        } else {
            qDebug() << "GET MODULE RETURN NULL!!!";
            return NULL;
        }
    }

    /**
     * The method set is supposed to be used for testing only.
     */
    template <typename T>
    static void set(InfoServicesModule* module)
    {
        s_modules[&typeid(T)] = module;
    }

private:
    static QMap<const std::type_info*, InfoServicesModule*> s_modules;

    static void addModule(InfoServicesModule* module);
};

#endif // INFOSERVICES_H
