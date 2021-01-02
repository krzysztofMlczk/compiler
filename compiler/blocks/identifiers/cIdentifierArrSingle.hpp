#ifndef CIDENTARRSINGLE_HPP
#define CIDENTARRSINGLE_HPP
#include "../../interfaces/iIdentifier.hpp"
#include <string>

/*
* class of an Identifier for a pidentifier(pidentifier) "type" variable
*/
class IdentifierArrSingle: public Identifier {
    public:
        string pid_ext;
        string pid_int;
        // Arr[pid] identifier constructor
        IdentifierArrSingle(string pid_ext, string pid_int);

        virtual string getCode();
};

#endif