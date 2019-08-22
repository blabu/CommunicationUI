#include <algorithm>
#include "cryptMessages.hpp"
#include "botan/sha2_64.h"
#include "botan/base64.h"
#include "botan/hex.h"
#include "MainProjectLoger.hpp"

cryptMessages::cryptMessages(std::string pass, std::shared_ptr<middlewareInterface> d) : delegate(d) {
    globalLog.addLog(Loger::L_TRACE, "Wrap connection to cryption");
    auto c = Botan::SHA_512().process(pass);
    memcpy(cypherKey,c.data(),32);
    memcpy(nonce,c.data()+32,32);
    globalLog.addLog(Loger::L_TRACE, Botan::hex_encode(cypherKey,32));
    globalLog.addLog(Loger::L_TRACE, Botan::hex_encode(nonce,32));
    globalLog.addLog(Loger::L_TRACE, Botan::hex_encode(c), " size is ", std::to_string(Botan::hex_encode(c).size()));
    enc = Botan::Cipher_Mode::create("AES-256/CBC/PKCS7", Botan::ENCRYPTION);
    dec = Botan::Cipher_Mode::create("AES-256/CBC/PKCS7", Botan::DECRYPTION);
    if(enc->default_nonce_length() > 32) {
        globalLog.addLog(Loger::L_ERROR, "Incorrect initialize vector size for cryption");
    }
    enc->set_key(cypherKey,32);
    dec->set_key(cypherKey,32);
}

void cryptMessages::write(const QByteArray & m) {
    globalLog.addLog(Loger::L_TRACE, "Encrypt write message ", m.toStdString());
    enc->start_msg(nonce,enc->default_nonce_length());
    QByteArray b(m);
    Botan::secure_vector<uint8_t> res(b.data(), b.data() + b.size());
    try {
        enc->finish(res);
        globalLog.addLog(Loger::L_TRACE, "Send encrypted message ", Botan::hex_encode(res));
        std::string codedResult = Botan::base64_encode(res);
        codedResult.push_back('\n');
        delegate->write(QByteArray(codedResult.data(), (unsigned int)codedResult.size()));
    }
    catch(Botan::Decoding_Error err) {
        QByteArray result(err.what());
        delegate->write("Error when try write crypt message");
    }
}

void cryptMessages::read(std::function<void (const QByteArray)> handler) {
    if(handler) {
        auto funcHandler = [this, handler](const QByteArray m){
            auto str = m.toStdString();
            str.pop_back();
            auto cryptText = Botan::base64_decode(str);
            globalLog.addLog(Loger::L_TRACE, "Receive encrypted message ", Botan::hex_encode(cryptText));
            this->dec->start_msg(this->nonce, dec->default_nonce_length());
            Botan::secure_vector<uint8_t> res(cryptText.data(), cryptText.data() + cryptText.size());
            try {
                dec->finish(res);
                QByteArray result(reinterpret_cast<const char *>(res.data()), (unsigned int)res.size());
                globalLog.addLog(Loger::L_TRACE, "Read decrypt message ", result.toStdString());
                handler(result);
            }
            catch(Botan::Decoding_Error err) {
                QByteArray result(err.what());
                handler(result);
            }

        };
        delegate->read(funcHandler);
    } else {
        delegate->read(handler);
    }
}

void cryptMessages::registerDisconnectEvent(std::function<void ()> handler) {
    delegate->registerDisconnectEvent([handler](){if(handler != nullptr) handler();});
}

