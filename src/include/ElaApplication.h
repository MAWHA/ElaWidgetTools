#ifndef ELAAPPLICATION_H
#define ELAAPPLICATION_H

#include <QIcon>
#include <QObject>

#include "singleton.h"
#include "ElaPropertyHelper.h"
#define eApp ElaApplication::getInstance()
class ElaApplicationPrivate;
class ELA_EXPORT ElaApplication : public QObject
{
    Q_OBJECT
    Q_Q_CREATE(ElaApplication)
    Q_SINGLETON_CREATE_H(ElaApplication)
    Q_PROPERTY_CREATE_Q_H(bool, IsApplicationClosed)
private:
    explicit ElaApplication(QObject* parent = nullptr);
    ~ElaApplication();

public:
    void init();
    static bool containsCursorToItem(QWidget* item);
};

#endif // ELAAPPLICATION_H
