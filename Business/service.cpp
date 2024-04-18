#include "service.h"
#include <vector>
#include <algorithm>
#include <random>

void ServiceEntitate::adauga_Entitate(const string &denumire, const string &varsta,const string &tip){
    Entitate a{denumire,varsta,tip};
    Entitate_Validator::validate(a);
    repo->adauga(a);
}

vector<Entitate> ServiceEntitate::filtreaza_dupa_tip(const string &tip) {
    vector<Entitate> entitate2;
    vector<Entitate> entitati = getAll();
    std::copy_if(entitati.begin(), entitati.end(), back_inserter(entitate2), [&tip](Entitate &a){return a.get_tip() == tip;});
    return entitate2;
}