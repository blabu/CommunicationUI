#ifndef CONSOLELOGER_H
#define CONSOLELOGER_H

#include "ILogerWriter.h"
#include <string>
#include <iostream>
#include <cstdio>

class ConsoleLoger : public ILogerWriter {
    std::string level;
public:
    ConsoleLoger(const std::string & lvl):level(lvl) {
        std::cout<<level<<": start loging"<<std::endl;
    }
    ConsoleLoger() = delete;
    virtual ~ConsoleLoger() {}
    void addLog(const std::string&& text) { /*std::cout<<level<<":"<<text<<std::endl;*/ }
    void flush() { std::flush(std::cout); }
    void flushLong() {flush();}
    void deleteAllLog() {}
};

#endif // CONSOLELOGER_H
