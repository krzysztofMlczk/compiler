#include "cIoHandler.hpp"

IOhandler::IOhandler(int argc, char** argv) {
    // skip program name from given params
    argc--;
    argv++;
    this->argc = argc;
    this->argv = argv;
}

FILE* IOhandler::read_code() {

    if (this->argc !=2 ) {
        throw Exception("Invalid amount of parameters\nProgram usage:\
        \nkompilator <input file> <output file>");
    }

    this->input_file = fopen(argv[0], "r");

    if (this->input_file == NULL){
        throw Exception("Unable to open file: " + std::string(argv[0]) + "\n");
    }
    return this->input_file;
}

/*
* Method for closing input file
*/
void IOhandler::close_input_file() {
    fclose(this->input_file);
}