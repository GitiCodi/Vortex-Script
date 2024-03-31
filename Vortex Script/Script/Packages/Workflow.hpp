#include <iostream>
#include <string>
#pragma once
#include <unordered_map>
#include <sstream>
#include <stdexcept>

namespace Flow {
    // Function to evaluate conditional statements
    static bool evaluateCondition(const std::string& condition, const std::string var1, const std::string var2) {
        if (condition == "==") {
            return std::stod(var1) == std::stod(var2);
        } else if (condition == "!=") {
            return std::stod(var1) != std::stod(var2);
        } else if (condition == ">") {
            return std::stod(var1) > std::stod(var2);
        } else if (condition == "<") {
            return std::stod(var1) < std::stod(var2);
        } else if (condition == ">=") {
            return std::stod(var1) >= std::stod(var2);
        } else if (condition == "<=") {
            return std::stod(var1) <= std::stod(var2);
        } else {
            throw std::invalid_argument("Invalid condition");
        }
    }
};