#ifndef CIDENTSINGLE_HPP
#define CIDENTSINGLE_HPP
#include "../../interfaces/iIdentifier.hpp"
#include <string>

/*
* class of an Identifier for a single variable
*/
class IdentifierSingle: public Identifier {
    public:
        string pid;
        // Single Identifier constructor
        IdentifierSingle(string pid);

        virtual string getCode();
};

#endif