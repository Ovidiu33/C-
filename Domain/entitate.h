#pragma once
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Entitate {
    string denumire;
    string varsta;
    string tip;
public:
    Entitate() = default;

    Entitate(string denumire,string varsta,string tip): denumire{denumire}, varsta{varsta},tip{tip}{
        //cout<<"Construit cu parametri\n";
    }

    Entitate(const Entitate& ot): denumire{ot.denumire},varsta{ot.varsta},tip{ot.tip}{
        //cout<<"Construit prin copiere!\n";
    }
    //setters
    void set_denumire(string denumired){
        denumire=denumired;
    }
    void set_varsta(string t){
        varsta=t;
    }
    void set_tip(string t){
        tip=t;
    }
    //getters
    string get_denumire() const{
        return denumire;
    }

    string get_tip() const{
        return tip;
    }
    string get_varsta() const{
        return varsta;
    }
    ~Entitate(){
        //out<<"Distrus\n";
    }
};
