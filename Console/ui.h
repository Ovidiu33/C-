#pragma once
#include "..//Business/service.h"

class ConsoleUI{
    ServiceEntitate& service;
//Functie de adaugare a unei bacterii
    void ui_adauga_Entitate();
// Functie pentru vizualizarea la microscop a bacteriilor initial
    static void ui_tipareste_initiala(const vector<Entitate>& entitati);
// Functie pentru vizualizarea la microscop a bacteriilor de un anumit tip
    void ui_filtreaza_dupa_tip();
    //void ui_vizualizareDupaTimp();

public:
    explicit ConsoleUI(ServiceEntitate& service): service{service}{}

    ConsoleUI(const ConsoleUI& ot) = delete;

    void start();
};