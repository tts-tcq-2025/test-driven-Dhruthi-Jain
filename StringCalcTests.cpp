#include "StringCalculator.h"
#include <cassert>
#include <iostream>

int main() {
    StringCalculator calc;

    assert(calc.add("") == 0);

    assert(calc.add("1") == 1);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
