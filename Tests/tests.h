#include "..//Business/service.h"
#include <cassert>

class Tests{
    ServiceEntitate& service;

    void test_entitate();
    void test_adauga_entitate();
    void test_filtrare();


public:
    explicit Tests(ServiceEntitate& service):service{service}{}
    Tests(const Tests& ot) = default;
    void test_all();
};
