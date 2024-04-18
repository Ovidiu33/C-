#include "Console/ui.h"
#include "Tests/tests.h"
#include "Validator/validate.h"

int main() {
    Repo_Entitate *repo;
    Entitate_Validator valid;
    ServiceEntitate service{repo, valid};
    ConsoleUI ui{service};
    Tests teste{service};
    //teste.test_all();
    ui.start();
}