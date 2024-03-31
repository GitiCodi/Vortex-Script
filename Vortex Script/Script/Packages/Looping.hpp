#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include "Storage.hpp"
#include "Workflow.hpp"
#include "Arithmetics.hpp"
#include "IO.hpp"



namespace Looping {
        static void executeStatement(const std::string& statement) {
        std::istringstream iss(statement);
        std::string token;
        iss >> token;
        if (token == "output") {
            std::string message;
            iss >> message;
            IO::outStream(message);
        } else if (token == "setVar") {
            std::string varName, value;
            iss >> varName >> value;
            Storage::setVar(varName, value);
        } else if (token == "while") {
            std::string condition, loopBody;
            iss >> condition;
            std::getline(iss, loopBody);
            executeWhileLoop(condition, loopBody);
        } else if (token == "for") {
            std::string initialization, condition, update, loopBody;
            iss >> initialization >> condition >> update;
            std::getline(iss, loopBody);
            executeForLoop(initialization, condition, update, loopBody);
        }
    }

        static void executeCodeBlock(const std::string& codeBlock) {
        std::istringstream iss(codeBlock);
        std::string line;
        while (std::getline(iss, line)) {
            executeStatement(line);
        }
    }

        static void executeForLoop(const std::string& initialization, const std::string& condition, const std::string& update, const std::string& loopBody) {
        executeCodeBlock(initialization);
        while (Flow::evaluateCondition(condition, "1", "1")) {
            executeCodeBlock(loopBody);
            executeCodeBlock(update);
        }
    }

    // Function to execute a while loop
    static void executeWhileLoop(const std::string& condition, const std::string& loopBody) {
        while (Flow::evaluateCondition(condition, "1", "1")) {
            executeCodeBlock(loopBody);
        }
    }

    // Function to execute a for loop

    // Function to execute a block of Vertox code


    // Function to execute a single statement of Vertox code

};
