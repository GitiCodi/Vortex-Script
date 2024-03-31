#pragma once
#include <iostream>

#include "Storage.hpp"
#include "Workflow.hpp"
#include "Arithmetics.hpp"


namespace IO{

    template<typename OutType>
    OutType outStream(OutType value)
    {
        std::cout << value << '\n';
        return value;
    }

    template<typename TextType, typename VariableType>
    TextType inStream(TextType text, VariableType store_in)
    {

        std::cout << text << '\n'; 
        std::cin >> store_in;
        return store_in;
    }

};
