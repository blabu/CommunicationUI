#ifndef BASE64MESSAGES_HPP
#define BASE64MESSAGES_HPP

#include <memory>
#include "middlewareInterface.hpp"

class base64Messages : public middlewareInterface
{
    std::shared_ptr<middlewareInterface> delegate;
public:
    base64Messages(std::shared_ptr<middlewareInterface> d);
    virtual ~base64Messages() = default;
    virtual void write(const QByteArray&m);
    virtual void read(std::function<void(const QByteArray)> handler);
    virtual void registerDisconnectEvent(std::function<void(void)> handler);
};

#endif // BASE64MESSAGES_HPP
