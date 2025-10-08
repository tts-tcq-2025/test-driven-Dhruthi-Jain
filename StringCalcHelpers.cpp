#include "StringCalculator.h"
#include <regex>
#include <string>
#include <vector>
#include <stdexcept>

std::vector<std::string> StringCalculator::splitNumbers(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> result;
    std::regex re(delimiter);
    std::sregex_token_iterator it(input.begin(), input.end(), re, -1);
    std::sregex_token_iterator end;
    for (; it != end; ++it) result.push_back(it->str());
    return result;
}

void StringCalculator::checkNegatives(const std::vector<int>& nums) {
    std::vector<int> negatives;
    for (int n : nums) if (n < 0) negatives.push_back(n);
    if (!negatives.empty()) {
        std::string msg = "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            msg += std::to_string(negatives[i]);
            if (i != negatives.size() - 1) msg += ", ";
        }
        throw std::runtime_error(msg);
    }
}
