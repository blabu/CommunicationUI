#include "base64Messages.hpp"
//#include "botan/base64.h"
//#include "botan/hex.h"

base64Messages::base64Messages(std::shared_ptr<middlewareInterface> d) : delegate(d) {

}

void base64Messages::write(const QByteArray &m){
    //std::string res = Botan::base64_encode(Botan::secure_vector<std::uint8_t>(m.data(), m.data()+m.size()));
    delegate->write(m.toBase64());
    return;
}

void base64Messages::read(std::function<void (const QByteArray)> handler) {
    if(handler) {
        auto func = [handler](const QByteArray m) {
            handler(QByteArray::fromBase64(m));
        };
        delegate->read(func);
    } else {
        delegate->read(handler);
    }
}

void base64Messages::registerDisconnectEvent(std::function<void ()> handler){
    delegate->registerDisconnectEvent(handler);
}
