#ifndef FOO_H
#define FOO_H

#include <QObject>
#include <QTimer>
#include <QPointer>
#include <QDebug>

//class CustomOjb;

#include <functional>

class Foo : public QObject
{
    Q_OBJECT
public:

    using FooCallback = std::function<void(int)>;

    explicit Foo(QObject *parent = 0);

    virtual ~Foo();

    void asyncWithSlot(QObject *caller, const char * slot);

    void asyncWithLambda(QObject *caller, FooCallback callback);

    void asyncWithSignal();

private slots:
    void onTimeoutSlot();

    void onTimeoutLambda();

    void onTimeoutSignal();

signals:
    void fooReply(int status);

private:
    QPointer<QObject> m_obj;
    QString m_slot;
    FooCallback m_callback;
};

#endif // EMITTEROBJ_H
