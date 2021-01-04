#include "iCommand.hpp"

/*
* Method for getting register as globbers
*/
vector<string> Command::getClobbers(vector<string>* occupied, ull amount) {
    vector<string> outcome;
    string registers[] = {"a", "b", "c", "d", "e", "f"};
    ull counter = 0;

    int i = 0;

    while (counter != amount) {
        if (!count(occupied->begin(), occupied->end(), registers[i])) {
            outcome.push_back(registers[i]);
            occupied->push_back(registers[i]);
            counter++;
        }
        i++;
    }
    
    return outcome;
}