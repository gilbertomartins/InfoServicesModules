#ifndef INFOSERVICESMODULE_H
#define INFOSERVICESMODULE_H

class InfoServicesModule
{
public:
    /**
     * Instantiates and connect all modules
     */
    virtual void init() = 0;

    /**
     * Start theads, timers and state machines
     */
    virtual void start() = 0;
    virtual ~InfoServicesModule() {}
};

#endif // INFOSERVICESMODULE_H
