#include <sstream>
#include "..//Business/service.h"
#include "..//Tests/tests.h"

void Tests::test_all() {

    service.memory_set("memorie");
    cout<<"memorie\n";
    test_entitate();
    test_adauga_entitate();
    test_filtrare();
    service.memory_set("fisier");
    cout<<"fisier\n";
}

void Tests::test_entitate() {
    Entitate a=Entitate("bacterie","secunda","1");
    a.set_denumire("a");
    assert(a.get_denumire()=="a");
    a.set_varsta("minut");
    assert(a.get_varsta()=="minut");
    a.set_tip("2");
    assert(a.get_tip()=="2");
}

void Tests::test_adauga_entitate() {
    service.adauga_Entitate("bacterie","secunda","1");
    const vector<Entitate> &entitati = service.getAll();
    assert(entitati.size() == 1);
    try{
        service.adauga_Entitate("bacterie","secunda","5");
    }
    catch (Validare& ex) {
        stringstream sout;
        sout<<ex;
    }
    try {
        service.adauga_Entitate("bacterie","secunda","1");
    }
    catch (RepoException& ex) {
        stringstream sout;
        sout<<ex;
    }
    cout<<"adauga\n";
}


void Tests::test_filtrare() {
    service.adauga_Entitate("bac","1","1");
    auto entitati = service.filtreaza_dupa_tip("1");
    service.adauga_Entitate("bacterie","5","2");
    assert(entitati[0].get_denumire() == "bac");
    assert(entitati[0].get_tip() == "1");
    assert(entitati[0].get_varsta() == "1");
    cout<<"filtrare\n";
}

