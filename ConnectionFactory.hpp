#ifndef TCPCONNECTION_HPP
#define TCPCONNECTION_HPP

#include "ReadWriteTcp.hpp"

class ConnectionFactory : public QObject {
    Q_OBJECT
public:
    // Синхронный вызов а возвращает nullptr
    static ReadWriteTcp* makeTCP(const QString ip, const QString port, int msTimeout);
};
#endif // TCPCONNECTION_HPP
