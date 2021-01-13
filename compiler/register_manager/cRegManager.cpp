#include "cRegManager.hpp"

RegManager::RegManager() {
    // constructor
    this->registers["a"] = true;
    this->registers["b"] = true;
    this->registers["c"] = true;
    this->registers["d"] = true;
    this->registers["e"] = true;
    this->registers["f"] = true;
}

/*
* makes reg occupied
*/
void RegManager::occupy(string reg) {
    this->registers[reg] = false;
}

/*
* makes reg free to use
*/
void RegManager::free(string reg) {
    this->registers[reg] = true;
}

vector<string> RegManager::getClobbers(int amount) {
    vector<string> clobbers;
    map<string, bool>::iterator it = this->registers.begin();
    int counter = 0;

    for (pair<string, bool> reg : this->registers) {
        if (counter == amount)
            break;
        string current_register = reg.first;
        bool is_free = reg.second;

        if (is_free) {
            clobbers.push_back(current_register);
            counter++;
        }
    }
    if (counter != amount) {
        throw Exception("Not enough clobbers");
    }
    return clobbers;
}

/*
* makes all registers free to use
*/

void RegManager::free_all() {
    for (pair<string, bool> reg : this->registers) {
        this->free(reg.first);
    }
}