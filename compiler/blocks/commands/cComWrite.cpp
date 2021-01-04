#include "cComWrite.hpp"

ComWrite::ComWrite(Value* val) {
    this->value = val;
}

vector<string> ComWrite::getCode(SymbolTable* symbolTable) {
    // UWAGA: tutaj potrzebuje w rejestrze otrzymac gdzie w pamieci znajduje sie dana wartosc
    // bo PUT x wypisze na ekran P[rx] - czyli w x musi się znajdować adres!!!

    // Jeśli value jest VariableValue, to ma pole ident => robiąc varVal.ident.getCode(), to dostaniemy w ident.outcome_reg adres varVal
    // Jeśli value jest Constant, to musimy wygenerować tą stałą, a następnie umieścić ją w pamięci, żeby móc ją wyświetlić!

}