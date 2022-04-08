//
// Created by Okada, Takahiro on 2018/02/04.
// Adapted to std C++ by Chuck Benedict on 2022/04/07.
//

#ifndef ARDUINO_WEB3_LOG_H
#define ARDUINO_WEB3_LOG_H

class Log {
public:
    void print(const char* s);
    void println(const char* s);
};

#endif //ARDUINO_WEB3_LOG_H
