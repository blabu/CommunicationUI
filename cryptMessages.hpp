#ifndef CRYPTMESSAGES_HPP
#define CRYPTMESSAGES_HPP

#include "middlewareInterface.hpp"
#include <memory>
#include <vector>
#include <botan/secmem.h>
#include "botan/cbc.h"


class cryptMessages : public middlewareInterface {
    std::uint8_t cypherKey[32];
    std::uint8_t nonce[32];
    std::unique_ptr<Botan::Cipher_Mode> enc;
    std::unique_ptr<Botan::Cipher_Mode> dec;
    std::shared_ptr<middlewareInterface> delegate;
    bool isConnected;
public:
    cryptMessages(std::string pass, std::shared_ptr<middlewareInterface> d);
    virtual ~cryptMessages() = default;
    virtual void write(const QByteArray&m);
    virtual void read(std::function<void(const QByteArray)> handler);
    virtual void registerDisconnectEvent(std::function<void(void)> handler);
};

#endif // CRYPTMESSAGES_HPP

