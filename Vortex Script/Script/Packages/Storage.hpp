#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Workflow.hpp"
#include "Arithmetics.hpp"
#include "IO.hpp"

namespace Storage {
    static std::unordered_map<std::string, std::string> storage; // Stores variables as key-value pairs

    // Function to set a variable
    static void setVar(const std::string& varName, const std::string& value) {
        storage[varName] = value;
    }

    // Function to get the value of a variable
    static std::string getVar(const std::string& varName) {
        if (storage.find(varName) != storage.end()) {
            return storage[varName];
        } else {
            return ""; // Variable not found, return empty string
        }
    }
};
