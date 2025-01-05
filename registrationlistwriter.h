#ifndef REGISTRATIONLISTWRITER_H
#define REGISTRATIONLISTWRITER_H

#include <QtXml>

#include "registrationlist.h"
#include "studentregistration.h"
#include "guestregistration.h"

class RegistrationListWriter
{
public:
    RegistrationListWriter(const RegistrationList& r);
    bool writeToXml(const QString& filePath);

private:
    const RegistrationList& regList;
};

#endif // REGISTRATIONLISTWRITER_H
