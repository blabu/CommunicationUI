#ifndef MIDDLEWAREINTERFACE_HPP
#define MIDDLEWAREINTERFACE_HPP
#include <QByteArray>
#include <functional>
#include "credentials.hpp"

class middlewareInterface {
public:
    explicit middlewareInterface() = default;
    virtual ~middlewareInterface() = default;
    virtual void write(const QByteArray&) = 0;
    virtual void read(std::function<void(const QByteArray)> handler) = 0;
    virtual void registerDisconnectEvent(std::function<void(void)> handler) = 0;
};

#endif // MIDDLEWAREINTERFACE_HPP
