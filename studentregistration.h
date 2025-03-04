#ifndef STUDENTREGISTRATION_H
#define STUDENTREGISTRATION_H

#include "registration.h"

class StudentRegistration : public Registration
{
    Q_OBJECT

public:
    StudentRegistration(Person *a, QString q);
    StudentRegistration(Person *a, QDate d, QString q);
    double calculateFee() const;
    QString toString() const;

private:
    QString m_Qualification;
};

#endif // STUDENTREGISTRATION_H
