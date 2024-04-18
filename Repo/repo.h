#pragma once
#include "..//Domain/entitate.h"
#include <utility>
#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Repo_Entitate{
public:
    Repo_Entitate() = default;

    virtual void adauga(const Entitate& a) = 0;

    virtual void sterge(int poz) = 0;

    virtual void modifica(const Entitate& a, int poz) = 0;

    virtual const Entitate& find(const string& denumire)= 0;

    virtual vector<Entitate> getAll() noexcept = 0;

    virtual int find_poz(const string& denumire) = 0;


    virtual ~Repo_Entitate() {}

};

class Repo_Entitate_memorie:public Repo_Entitate{
    vector<Entitate> all;
    bool exist(const Entitate& a);

public:
    Repo_Entitate_memorie() = default;

    /// adaugare in lista all noua entitate
    /// \param a - const Entitate&
    void adauga(const Entitate& a) override;

    /// stergere din lista all entiatea de pe pozitia poz
    /// \param poz - int
    void sterge(int poz) override;
    /// modifica activitatea de pe pozitia poz cu entitatea a
    /// \param a - const Entitate&
    /// \param poz - int
    void modifica(const Entitate& a, int poz) override;
    ///gaseste entitatea cu denumirea ceruta
    ///in functie de param denumire -const string& denumire
    const Entitate& find(const string& denumire) override;
    //returneaza toate entitatile
    vector<Entitate> getAll() noexcept override;
    //gaseste entitate dupa pozitie in vector
    int find_poz(const string& denumire) override;
    //destuctor
    ~Repo_Entitate_memorie() override = default;
    //golire
    void clear_all(){
        all.clear();
    };
};


class Repo_Entitate_fisier:public Repo_Entitate_memorie{
    string fisier = "..//bacterii.txt";

    void load_from_file(string& fis);

    void save_to_file(string& fis);

public:
    Repo_Entitate_fisier() = default;

    /// adaugare in lista all noua entitate
    /// \param a - const Entitate&
    void adauga(const Entitate& a) override{
        load_from_file(fisier);
        Repo_Entitate_memorie::adauga(a);
        save_to_file(fisier);
    }
    /// stergere din lista all entitatea de pe pozitia poz
    /// \param poz - int
    void sterge(int poz) override{
        load_from_file(fisier);
        Repo_Entitate_memorie::sterge(poz);
        save_to_file(fisier);
    }

    /// modifica entitatea de pe pozitia poz cu entitatea a
    /// \param a - const Entitate&
    /// \param poz - int
    void modifica(const Entitate& a, int poz) override{
        load_from_file(fisier);
        Repo_Entitate_memorie::modifica(a, poz);
        save_to_file(fisier);
    }

    const Entitate & find(const string& titlu) override{
        load_from_file(fisier);
        return Repo_Entitate_memorie::find(titlu);
    }

    vector<Entitate> getAll()noexcept override{
        load_from_file(fisier);
        return Repo_Entitate_memorie::getAll();
    }

    int find_poz(const string& denumire) override{
        load_from_file(fisier);
        return Repo_Entitate_memorie::find_poz(denumire);
    }


    ~Repo_Entitate_fisier() override = default;
};
class RepoException{
    string msg;

public:
    explicit RepoException(string m):msg(std::move( m )){}

    friend ostream& operator<<(ostream& out, const RepoException& ex);
};

ostream& operator<<(ostream& out, const RepoException& ex);