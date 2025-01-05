#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>

#include "registrationfactory.h"

#include "userinfodialog.h"
#include "registrationlistwriter.h"
#include "registrationlistreader.h"

class RegistrationWindow : public QMainWindow
{
    Q_OBJECT

public:
    RegistrationWindow(QWidget *parent = nullptr);
    ~RegistrationWindow();
    void updateTable() const;

private:
    Person *person;
    QTableWidget *tableOfRegisters;
    QPushButton *registerB;
    QPushButton *findB;
    QPushButton *saveB;
    QLineEdit *searchEdit;
    RegistrationList rList;
    QComboBox *combAtt;
    QComboBox *feeBox;
    RegistrationListReader *xmlReader;

    RegistrationFactory *regFactory = RegistrationFactory::getInstance();

private slots:
    void addRegistration();
    void findPerson();
    void textChage();
    void numberAttendees();
    void calculateFee();
    void writeToXML();
    void readXML();

};
#endif // REGISTRATIONWINDOW_H
