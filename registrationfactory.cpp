#include "registrationfactory.h"

RegistrationFactory* RegistrationFactory::onlyInstance = nullptr;

RegistrationFactory* RegistrationFactory::getInstance()
{
    if (onlyInstance == nullptr)
        onlyInstance = new RegistrationFactory();
    return onlyInstance;
}

Registration *RegistrationFactory::createRegistration(QString t, Person *p, QString cOq, QDate d) const
{
    Registration *r = nullptr;

    if (t == "Registration")
        r = new Registration(p, d);
    else if (t == "StudentRegistration")
        r = new StudentRegistration(p, d, cOq);
    else if (t == "GuestRegistration")
        r = new GuestRegistration(p, d, cOq);

    return r;
}

RegistrationFactory::RegistrationFactory()
    {/*intentionally empty*/}

