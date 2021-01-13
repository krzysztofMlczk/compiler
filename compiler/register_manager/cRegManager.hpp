#ifndef CREGMAN_HPP
#define CREGMAN_HPP
#include "../exceptions/cException.hpp"
#include <vector>
#include <string>
#include <map>

using namespace std;

/*
* Register Manager Class
*/
class RegManager {
    public:
        map<string, bool> registers;// "a": true - means reg a is free to use
        RegManager();
        void occupy(string reg); // makes reg occupied
        void free(string reg); // makes reg free to use
        void free_all(); // makes all registers free to use
        vector<string> getClobbers(int amount); // returns vector of clobbers
};

#endif