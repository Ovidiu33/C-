#include "ui.h"
#include <iostream>
#include <string>

using namespace std;

void ConsoleUI::ui_tipareste_initiala(const vector<Entitate>& entitati) {
    if(entitati.empty())
    {
        cout<<"Nu exista entitati\n";
        return;
    }
    cout<<"entitati:\n";
    for (const auto& Entitate:entitati) {
        cout << Entitate.get_denumire()<<" "<<Entitate.get_varsta()<<" "<<Entitate.get_tip()<<" "<<endl;
    }
    cout<<"Sfarsit lista entitati!\n";
}

void ConsoleUI::ui_adauga_Entitate() {
    string denumire,varsta,tip;
    cout<<"Dati denumire:";
    getline(cin>>ws,denumire);
    cout<<"Dati varsta:";
    getline(cin>>ws,varsta);
    cout<<"Dati tip:";
    getline(cin, tip);
    service.adauga_Entitate(denumire,varsta,tip);
    cout<<"entitate adaugata cu succes!\n";
}

void ConsoleUI::ui_filtreaza_dupa_tip() {
    string tip;
    cout<<"Dati tip:";
    cin>>tip;
    auto entitati2 = service.filtreaza_dupa_tip(tip);
    if(entitati2.empty())
    {
        cout<<"Nu exista entitati\n";
        return;
    }
    cout<<"entitati:\n";
    for(const auto& Entitate: entitati2)
    {
        cout<<Entitate.get_denumire()<<" "<<Entitate.get_varsta()<<" "<<Entitate.get_tip()<<" "<<Entitate.get_tip()<<" \n";
    }
    cout<<"Sfarsit lista entitate.\n";
}
/*
void ConsoleUI::ui_vizualizareDupaTimp() {
    int timp;
    cout<<"Dati timp";
    cin>>timp;
    cout << "Bacteriile de pe lamela dupa " << timp << " unitati de timp sunt:\n";
    vector<Entitate> bacteriiFinale;

    for (const auto& bacteria : Entitate) {
        Entitate bacteriaNoua;
        bacteriaNoua.set_denumire(bacteria.get_denumire());
        bacteriaNoua.set_varsta(reinterpret_cast<const char *>(stoi(bacteria.get_varsta()) + timp));
        bacteriaNoua.set_tip(bacteria.get_tip());

        if (bacteria.get_tip() == "1") {
            bacteriiFinale.push_back(bacteriaNoua);
            bacteriiFinale.push_back(bacteriaNoua);
        } else if (bacteria.get_tip()== "2") {
            if (bacteria.get_varsta() >= "3") {
                bacteriaNoua.set_tip("1");
                bacteriiFinale.push_back(bacteriaNoua);
            }
            bacteriiFinale.push_back(bacteriaNoua);
        }
    }

    for (const auto& bacteria : bacteriiFinale) {
        cout<<bacteria.get_denumire()<<" "<<bacteria.get_varsta()<<" "<<bacteria.get_tip()<<" "<<bacteria.get_tip()<<" \n";
    }
}
*/

void ConsoleUI::start()
{
    cout<<"Unde vor fi stocate datele:\n";
    cout<<"1. Fisier\n";
    cout<<"2. Memorie interna\n";
    int tip_memo;
    cin>>tip_memo;
    switch (tip_memo) {
        case 1:
            service.memory_set("fisier");
            break;
        case 2:
            service.memory_set("memorie");
            break;
        default:
            cout<<"Alegere invalida!\n";
    }
    cout<<"\n\n";
    while (true){
        cout<<"1. Adauga bacterie\n";
        cout<<"2. Vizualizarea la microscop a bacteriilor initial plasate pe lamela\n";
        cout<<"3. Vizualizarea la microscop a bacteriilor (de un anumit tip) plasate initial pe lamela\n";
        cout<<"0. Exit\n";
        cout<<"Introdu comanda:";
        int comanda;
        cin>>comanda;
        try{
            switch (comanda) {
                case 1:
                    ui_adauga_Entitate();
                    break;
                case 2:
                    ui_tipareste_initiala(service.getAll());
                    break;
                case 3:
                    ui_filtreaza_dupa_tip();
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 0:
                    return;
                default:
                    cout<<"Comanda invalida!\n";
            }
        }
        catch(const RepoException& ex)
        {cout<<ex<<endl;}

        catch(const Validare& ev)
        {cout<<ev<<endl;}
    }
}
