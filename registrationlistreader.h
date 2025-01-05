#ifndef REGISTRATIONLISTREADER_H
#define REGISTRATIONLISTREADER_H

#include <QtXml>
#include <QFile>
#include <QMessageBox>

#include "registrationfactory.h"

class RegistrationListReader
{
public:

    RegistrationListReader();
    QList<Registration* > parseXML(const QString &f);

private:
    Registration* parseRElement(QXmlStreamReader& xmlReader);
    RegistrationFactory *regFactory = RegistrationFactory::getInstance();

};

#endif // REGISTRATIONLISTREADER_H
