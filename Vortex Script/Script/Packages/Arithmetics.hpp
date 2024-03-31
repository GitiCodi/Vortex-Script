#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include "Storage.hpp"
#include "Workflow.hpp"
#include "IO.hpp"

namespace Arithmetic {

    // Function to perform arithmetic operations on variables
    static std::string calculate(const std::string& op, const std::string& var1, const std::string& var2) {
        try {
            double val1 = std::stod(var1);
            double val2 = std::stod(var2);
            double result;
            if (op == "+") {
                result = val1 + val2;
            } else if (op == "-") {
                result = val1 - val2;
            } else if (op == "*") {
                result = val1 * val2;
            } else if (op == "/") {
                if (val2 == 0) {
                    throw std::invalid_argument("Division by zero");
                }
                result = val1 / val2;
            } else {
                throw std::invalid_argument("Invalid operator");
            }
            return std::to_string(result);
        } catch (const std::exception& e) {
            return "Error: " + std::string(e.what());
        }
    }
};