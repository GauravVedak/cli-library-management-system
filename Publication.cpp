// Final Project
// Publication Module
// File    Publication.cpp
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string> 
#include <iomanip>
#include "Publication.h"
#include "Lib.h"

using namespace std;

namespace sdds
{
    Publication::Publication()
    {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();
    }

    Publication::Publication(const Publication& other)
    {
        m_title = nullptr;
        *this = other;
    }

    Publication& Publication::operator=(const Publication& other)
    {
        if (this != &other)
        {
            set(other.m_membership);
            setRef(other.m_libRef);
            strcpy(m_shelfId, other.m_shelfId);
            m_date = other.m_date;

            if (other.m_title != nullptr)
            {
                delete[] m_title;
                strcpy(m_shelfId, other.m_shelfId);
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
        }
        else
        {
            m_title = nullptr;
        }
        return *this;
    }

    Publication::~Publication()
    {
        delete[] m_title;
        m_title = nullptr;
    }

    void Publication::set(int member_id)
    {
        m_membership = member_id > 9999 && member_id <= 99999 ? member_id : 0;
    }

    void Publication::setRef(int value)
    {
        m_libRef = value;
    }

    void Publication::resetDate()
    {
        m_date.setToToday();
    }

    char Publication::type() const
    {
        return 'P';
    }

    bool Publication::onLoan() const
    {
        if (m_membership != 0)
        {
            return true;
        }
        return false;
    }

    Date Publication::checkoutDate() const
    {
        return m_date;
    }

    bool Publication::operator==(const char* title) const
    {
        bool p = strstr(m_title, title);
        if (p)
        {
            return true;
        }
        return false;
    }

    Publication::operator const char* () const
    {
        return m_title;
    }

    int Publication::getRef() const
    {
        return m_libRef;
    }

    bool Publication::conIO(ios& io) const
    {
        if (&io == &cin || &io == &cout)
        {
            return true;
        }
        return false;
    }

    ostream& Publication::write(ostream& os) const
    {
        char oldfill = os.fill();
        if (conIO(os))
        {
            os << "| "
                << setw(SENECA_SHELF_ID_LEN) << left << setfill(' ') << m_shelfId << " | ";

            if (strlen(m_title) > SENECA_TITLE_WIDTH)
            {
                for (int i = 0; i < SENECA_TITLE_WIDTH; ++i)
                {
                    os << m_title[i];
                }
            }
            else
            {
                os.fill('.');
                os << setw(SENECA_TITLE_WIDTH) << left << m_title;
            }
            os << " | ";
            os.fill(oldfill);

            if (m_membership == 0)
            {
                cout << " N/A ";
            }
            else
            {
                os << m_membership;
            }

            os << " | ";
            os << m_date;
            os << " |";
        }
        else
        {
            os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
        }
        return os;
    }

    istream& Publication::read(istream& is)
    {
        if (m_title != nullptr)
            delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date.setToToday();

        char title[256]{};
        char id[SENECA_SHELF_ID_LEN + 1]{};
        int memberShip = 0;
        int libRef = -1;
        Date date;

        if (conIO(is))
        {
            cout << "Shelf No: ";
            is.getline(id, SENECA_SHELF_ID_LEN + 1, '\n');

            if (strlen(id) != SENECA_SHELF_ID_LEN)
            {
                is.setstate(ios::failbit);
            }

            cout << "Title: ";
            is.getline(title, 257, '\n');

            cout << "Date: ";
            is >> date;


        }
        else
        {
            is >> libRef;
            is.ignore();
            is.getline(id, SENECA_SHELF_ID_LEN + 1, '\t');
            is.getline(title, 257, '\t');
            is >> memberShip;
            is.ignore();
            is >> date;
        }

        if (!date)
        {
            is.setstate(std::ios::failbit);
        }

        if (is)
        {
            delete[] m_title;
            m_title = nullptr;
            m_title = new char[strlen(title) + 1];
            strcpy(m_title, title);
            strcpy(m_shelfId, id);
            set(memberShip);
            m_date = date;
            setRef(libRef);
        }

        return is;
    }

    Publication::operator bool() const
    {
        if (m_shelfId != nullptr && m_title != nullptr && m_title[0] != '\0' && m_shelfId[0] != '\0')
            return true;
        return false;
    }
}