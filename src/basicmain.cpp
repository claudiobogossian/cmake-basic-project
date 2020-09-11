#include "basiclib.h"

#include <iostream>

int main() {

    BasicLib l;
    std::cout << "Testing" << std::endl;
    l.testBoost();
    l.testCurl();


    std::cout << "Finish" << std::endl;

    return 0;
}
