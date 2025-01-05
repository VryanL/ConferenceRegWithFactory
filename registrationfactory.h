#ifndef REGISTRATIONFACTORY_H
#define REGISTRATIONFACTORY_H

#include "registration.h"
#include "studentregistration.h"
#include "guestregistration.h"

class RegistrationFactory
{
public:
    static RegistrationFactory *getInstance();
    Registration* createRegistration(QString t, Person* p, QString cOq = "", QDate d = QDate::currentDate()) const;

private:
    RegistrationFactory();
    static RegistrationFactory* onlyInstance;

};

#endif // REGISTRATIONFACTORY_H
