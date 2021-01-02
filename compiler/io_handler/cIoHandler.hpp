#ifndef CIOHAN_HPP
#define CIOHAN_HPP
#include <iostream>
#include <cstdio>
#include "../exceptions/cException.hpp"

/*
* IO handler class
*/
class IOhandler {
    public:
        int argc;
        char** argv;
        FILE* input_file;
        IOhandler(int argc, char** argv);
        FILE* read_code();
        void close_input_file();
};

#endif