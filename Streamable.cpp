// Final Project
// Streamable Module
// File    Streamable.cpp
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#include <iostream> 
#include "Streamable.h"

using namespace std;

namespace sdds
{
    std::ostream& operator<<(std::ostream& os, const Streamable& stream)
    {
        if (stream)
            stream.write(os);
        
        return os;
    }
    std::istream& operator >> (std::istream& is, Streamable& stream)
    {
        stream.read(is);

        return is;
    }

    Streamable::~Streamable()
    {

    }
}