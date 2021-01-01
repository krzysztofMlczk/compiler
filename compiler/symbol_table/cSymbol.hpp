#ifndef CSYM_HPP
#define CSYM_HPP
#include <string>
typedef unsigned long long ull;

/*
*   Symbol class
*/
class Symbol {
    public:
        std::string name;
        ull offset; //position in memory
        ull value;
        bool initialized;
        bool is_array;
        bool is_iterator;
        ull array_start;
        ull array_end;
        ull size;

        // constructors
        // Normal Variable
        Symbol(std::string name, ull offset);
        // Array Variable
        Symbol(std::string name, ull offset, ull arr_start, ull arr_end);
};

#endif