#include "registrationlistwriter.h"

RegistrationListWriter::RegistrationListWriter(const RegistrationList &r)
    :regList(r)
{/*intentionally empty*/}


/*
<registrationlist>
    <registration type="Registration">
     <attendee>
      <name>..</name>
      <affliation>..</affliation>
      <email>..</email>
      </attendee>
      <bookingdate>..</bookingdate>
      <registrationfee>..</registrationfee>
      </registration>
      ..
      ..
    </registrationlist>
*/

bool RegistrationListWriter::writeToXml(const QString &filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QDomDocument document;
    QDomElement root = document.createElement("registrationlist");
    document.appendChild(root);

    const QList<Registration*>& registration = regList.getAttendeeList();

    for (const Registration* r : registration)
    {
        QString type = r->metaObject()->className();
        QStringList getR;
        getR << r->toString().split(' ', Qt::SkipEmptyParts);

        QDomElement registrationElement = document.createElement("registration");
        registrationElement.setAttribute("type", type);

        QDomElement attendeeElement = document.createElement("attendee");

        QDomElement nameElement = document.createElement("name");
        nameElement.appendChild(document.createTextNode(r->getAttendee()->getName()));
        attendeeElement.appendChild(nameElement);

        QDomElement affiliationElement = document.createElement("affiliation");
        affiliationElement.appendChild(document.createTextNode(r->getAttendee()->getAffiliation()));
        attendeeElement.appendChild(affiliationElement);

        QDomElement emailElement = document.createElement("email");
        emailElement.appendChild(document.createTextNode(r->getAttendee()->getEmail()));
        attendeeElement.appendChild(emailElement);

        registrationElement.appendChild(attendeeElement);

        QDomElement bookingElement = document.createElement("bookingdate");
        bookingElement.appendChild(document.createTextNode(r->getBookingDate().toString(Qt::ISODate)));
        registrationElement.appendChild(bookingElement);

        QDomElement feeElement = document.createElement("registrationfee");
        feeElement.appendChild(document.createTextNode(QString::number(r->calculateFee(),'f',2)));
        registrationElement.appendChild(feeElement);


        if (type == "StudentRegistration")
        {
            QDomElement qualificationElement = document.createElement("qualification");
            qualificationElement.appendChild(document.createTextNode(getR.last()));
            registrationElement.appendChild(qualificationElement);
        }
        else if (type == "GuestRegistration")
        {
            QDomElement categoryElement = document.createElement("category");
            categoryElement.appendChild(document.createTextNode(getR.last()));
            registrationElement.appendChild(categoryElement);
        }

        root.appendChild(registrationElement);

    }

    QTextStream out(&file);
    out << document.toString();
    file.close();

    return true;
}
/* QDomDocument doc;
 * QDomElement root = doc.createElement("Name");
 * doc.appendChild(root);
 * for ()
 * {
 *      QDomElement nameT = doc.createElement("NameT");
 *      root.appendChild(nameT);
 *      QDomText value = doc.createTextNode("value");
 *      nameT.appendChild(value);
 * }
 * <Name>
 *      <NameT>value<NameT>
*/
