#include "StringCalculator.h"
#include <cassert>
#include <iostream>

int main() {
    StringCalculator calc;

    assert(calc.add("") == 0);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
