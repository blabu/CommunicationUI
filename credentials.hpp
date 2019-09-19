#ifndef CREDENTIALS_HPP
#define CREDENTIALS_HPP
#include <QString>

// Данные введенные пользователем простая DTO-шка
struct Credentials {
    QString id;
    QString password;
    QString sessionKey;
    QString identifierTo;
    QString serverAddr;
    QString serverPort;
};

struct ModemProperties {
    QString baudrate;
    QString rs232Timeout;
    QString modemTimeout;
    QString serverIP;
};

#endif // CREDENTIALS_HPP
