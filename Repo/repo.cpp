#include "repo.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void Repo_Entitate_memorie::adauga(const Entitate &a){
    if(exist(a)){
        throw RepoException("Exista deja Entitate!");
    }
    all.push_back(a);
}

void Repo_Entitate_memorie::sterge(int poz) {
    all.erase(all.begin()+poz);
}


void Repo_Entitate_memorie::modifica(const Entitate &a, int poz) {
    all[poz] = a;
}

bool Repo_Entitate_memorie::exist(const Entitate &a) {
    string id =a.get_denumire();
    auto rezultat = find_if(all.begin(), all.end(), [&id](const Entitate& a){return a.get_denumire() == id;});
    if(rezultat == all.end())
        return false;
    else return true;
}

const Entitate& Repo_Entitate_memorie::find(const string& denumire) {
    auto rezultat = find_if(all.begin(), all.end(), [&denumire](const Entitate& a){return a.get_denumire() == denumire;});
    if(rezultat == all.end())
        throw RepoException("Nu exista Entitate!");
    else return *rezultat;
}

vector<Entitate> Repo_Entitate_memorie::getAll()noexcept {
    return all;
}


int Repo_Entitate_memorie::find_poz(const string& denumire) {
    int poz=0;
    for (auto &Entitate: getAll()) {
        if(Entitate.get_denumire() == denumire)
            return poz;
        poz++;
    } }


ostream& operator<<(ostream& out, const RepoException& ex){
    out<<ex.msg;
    return out;
}

void Repo_Entitate_fisier::load_from_file(string &file_input) {
    Repo_Entitate_memorie::clear_all();
    std::ifstream in(file_input);
    string line;
    while(getline(in,line))
    {
        vector<string>str;
        stringstream ss(line);
        string cell;
        while(getline(ss,cell,','))
            str.push_back(cell);
        string denumire=str[0];
        string varsta=str[1];
        string tip=str[2];
        Entitate o{denumire,varsta,tip};
        Repo_Entitate_memorie::adauga(o);
    }
    in.close();
}

void Repo_Entitate_fisier::save_to_file(string &fis) {
    ofstream out(fis);
    for (const auto& Entitate:Repo_Entitate_memorie::getAll()) {
        if(!(Entitate.get_denumire().empty()))
            out<< Entitate.get_denumire()<<","<<Entitate.get_varsta()<<","<<Entitate.get_tip()<<endl;
    }
    Repo_Entitate_memorie::clear_all();
    out.close();
}
