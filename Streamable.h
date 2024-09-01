// Final Project
// Streamable Module
// File    Streamable.h
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SENECA_ISTREAMABLE_H
#define SENECA_ISTREAMABLE_H
#include <iostream>

namespace sdds
{
    class Streamable
    {
    public:
        virtual std::ostream& write(std::ostream& os) const = 0;
        virtual std::istream& read(std::istream& is) = 0;
        virtual bool conIO(std::ios& ios) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable();
        friend std::ostream& operator<<(std::ostream& os, const Streamable& stream);
        friend std::istream& operator >> (std::istream& is, Streamable& stream);

    };
}

#endif