#include "StringCalculator.h"
#include <regex>
#include <string>
#include <vector>

int StringCalculator::add(const std::string& input) {
    if (input.empty()) return 0;

    std::string numbers = input;
    std::string delimiter = ",|\n";

    std::regex customDelimRegex("^//(\\[.*\\]|.)\n");
    std::smatch match;
    if (std::regex_search(numbers, match, customDelimRegex)) {
        std::string raw = match[1];
        if (raw.front() == '[' && raw.back() == ']') raw = raw.substr(1, raw.size() - 2);
        delimiter = raw;
        numbers = numbers.substr(match[0].length());
    }

    auto tokens = splitNumbers(numbers, delimiter);
    std::vector<int> nums;
    for (auto& t : tokens) {
        if (t.empty()) continue;
        int n = std::stoi(t);
        if (n <= 1000) nums.push_back(n);
    }

    checkNegatives(nums);

    int sum = 0;
    for (int n : nums) sum += n;
    return sum;
}
