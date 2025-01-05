#include "registrationlistreader.h"

RegistrationListReader::RegistrationListReader()
{/*intentionally empty*/}

QList<Registration*> RegistrationListReader::parseXML(const QString &f)
{
    QList<Registration*> registrations;

    QFile file(f);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "Failed to open XML file for reading.");
        return registrations;
    }

    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&file);

    while (!xmlReader.atEnd() && !xmlReader.hasError())
    {
        xmlReader.readNext();
        if (xmlReader.isStartElement())
        {
            if (xmlReader.name().toString() == "registration")
            {
                Registration* registration = parseRElement(xmlReader);
                if (registration)
                {
                    registrations.append(registration);
                }
            }
        }
    }

    if (xmlReader.hasError()) {
        QMessageBox::critical(nullptr, "Error", "XML Parsing Error: " + xmlReader.errorString());
    }

    file.close();
    return registrations;
}

Registration *RegistrationListReader::parseRElement(QXmlStreamReader &xmlReader)
{
    QString type = xmlReader.attributes().value("type").toString();
    Person* person = nullptr;
    QString nameR;
    QString affiliationR;
    QString emailR;
    QDate dateR;
    QString categoryR;
    QString qualificationR;

    while (!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name().toString() == "registration"))
    {
        xmlReader.readNext();
        if (xmlReader.tokenType() == QXmlStreamReader::StartElement)
        {
            QString elementName = xmlReader.name().toString();
            xmlReader.readNext();
            QString elementText = xmlReader.text().toString();

            if (elementName == "name")
            {
                nameR = elementText;
            }
            else if (elementName == "affiliation")
            {
                affiliationR = elementText;
            }
            else if (elementName == "email")
            {
                emailR = elementText;
            }
            else if (elementName == "bookingdate")
            {
                dateR = QDate::fromString(elementText, Qt::ISODate);
            }
            else if (elementName == "qualification")
            {
                qualificationR = elementText;
            }
            else if (elementName == "category") {
                categoryR = elementText;
            }
        }
    }

    if (type == "Registration") {
        person = new Person(nameR, affiliationR, emailR);
        return regFactory->createRegistration("Registration", person, "", dateR);
    } else if (type == "StudentRegistration") {
        person = new Person(nameR, affiliationR, emailR);
        return regFactory->createRegistration("StudentRegistration", person, qualificationR, dateR);
    } else if (type == "GuestRegistration") {
        person = new Person(nameR, affiliationR, emailR);
        return regFactory->createRegistration("GuestRegistration", person, categoryR, dateR);
    }

    return nullptr;
}
