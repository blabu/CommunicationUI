#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP
#include <QString>

// Данные введенные пользователем простая DTO-шка
struct Credentials {
    QString id;
    QString serverAddr;
    QString serverPort;
    QString password;
    QString identifierTo;
};

#endif // CREDENTIALS_HPP
