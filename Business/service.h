#pragma once

#include "..//Repo/repo.h"
#include "..//Validator/validate.h"
#include <string>
#include <utility>
#include <vector>
#include <functional>
#include <map>
#include <memory>
#include <iterator>

using namespace std;

class ServiceEntitate{
    Repo_Entitate* repo;

public:
    ServiceEntitate(Repo_Entitate *rep, Entitate_Validator &val): repo{rep}{}
    //returneaza toate entitatile
    vector<Entitate> getAll() noexcept{
        return repo->getAll();
    }
    /// preia parametrii din ui si ii trimite sub forma de entitate in repo pentru adaugare
    /// \param denumire const string& - denumirea noii entitati
    /// \param varsta const string& - varstal noii entitati
    /// \param tip const string& -tipul noii entitati
    void adauga_Entitate(const string &denumire, const string &varsta, const std::string &tip);

    /// sterge entitatea cu varstal varsta
    /// \param varsta const string&
    /// \return 1 - se realizeaza stergerea
    ///         0 - nu se realizeaza stergerea
    //filtreaza entitatea dupa un tip dat
    vector<Entitate> filtreaza_dupa_tip(const string& basicString);

    //functia prin care decide userul cum vrea sa foloseasca aplicatia
    void memory_set(const string& rep){
        if(rep == "fisier"){
            repo = new Repo_Entitate_fisier();
        }
        if (rep == "memorie")
            repo = new Repo_Entitate_memorie();
    }
};

