#include "StringCalculator.h"
#include <cassert>
#include <iostream>

int main() {
    StringCalculator calc;

    assert(calc.add("") == 0);

    assert(calc.add("1") == 1);

    assert(calc.add("1,2") == 3);

    assert(calc.add("1,2,3,4") == 10);

    assert(calc.add("1\n2,3") == 6);

    assert(calc.add("//;\n1;2") == 3);
    
    assert(calc.add("//[***]\n1***2***3") == 6);

    try { calc.add("1,-2,3"); assert(false); }
    catch (const std::runtime_error& e) { assert(std::string(e.what()) == "negatives not allowed: -2"); }

    try { calc.add("1,-2,-3"); assert(false); }
    catch (const std::runtime_error& e) { assert(std::string(e.what()) == "negatives not allowed: -2, -3"); }

    assert(calc.add("2,1001") == 2);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
