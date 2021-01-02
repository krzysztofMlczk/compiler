#ifndef CEXEPT_HPP
#define CEXEPT_HPP
#include <exception>
#include <string>

class Exception: public std::exception {
    private:
        std::string msg;
    public:
        Exception(std::string msg):msg(msg){}
        virtual const char* what() const noexcept {
            return msg.c_str();
        }
};

#endif