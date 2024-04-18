#pragma once
#include "..//Domain/entitate.h"
#include <string>
#include <vector>

using namespace std;

class Validare{
    vector<string> msg;
public:
    explicit Validare(const vector<string>& errors): msg{ errors }{}

    friend ostream& operator<<(ostream& out, const Validare& ex);
};

ostream& operator<<(ostream& out, const Validare& ex);

class Entitate_Validator{
public:
    static void validate(const Entitate& a);
};