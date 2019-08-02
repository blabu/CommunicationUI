#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP
#include <QString>

// Данные введенные пользователем простая DTO-шка
struct Credentials {
    QString id;
    QString password;
    QString identifierTo;
    QString serverAddr;
    QString serverPort;
};

#endif // CREDENTIALS_HPP
