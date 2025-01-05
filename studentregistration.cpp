#include "studentregistration.h"

StudentRegistration::StudentRegistration(Person *a, QString q)
    : Registration(a), m_Qualification(q)
{/*intentionally empty*/}

StudentRegistration::StudentRegistration(Person *a, QDate d, QString q)
    : Registration(a,d), m_Qualification(q)
{/*intentionally empty*/}

double StudentRegistration::calculateFee() const
{
    return STANDARD_FEE * 0.5;
}

QString StudentRegistration::toString() const
{
    QString s = getAttendee()->toString() + " "
                + "R" + QString::number(calculateFee(),'f',2) + " "
                + getBookingDate().toString(Qt::ISODate) + " "
                + m_Qualification;
    return s;
}
