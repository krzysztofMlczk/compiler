#include "cSymbol.hpp"

Symbol::Symbol(std::string name, ull offset) {
    this->name = name;
    this->offset = offset;
    this->initialized = false;
    this->is_iterator = false;
    this->is_array = false;
    this->size = 1;
}

Symbol::Symbol(std::string name, ull offset, ull arr_start, ull arr_end) {
    this->name = name;
    this->offset = offset;
    this->initialized = true; //array elements dont have to be initialized
    this->is_array = true;
    this->is_iterator = false;
    this->array_start = arr_start;
    this->array_end = arr_end;
    this->size = arr_end - arr_start + 1;
}