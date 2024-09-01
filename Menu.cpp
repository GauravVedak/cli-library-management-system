// Final Project
// Menu Module
// File    Menu.cpp
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"

namespace sdds
{
    MenuItem::MenuItem() : m_content(nullptr) {}

    MenuItem::MenuItem(const char* itemContent)
    {
        if (itemContent)
        {
            m_content = new char[strlen(itemContent) + 1];
            strcpy(m_content, itemContent);
        }
        else
        {
            m_content = nullptr;
        }
    }

    MenuItem::operator bool() const
    {
        if (m_content != nullptr && m_content[0] != '\0')
        {
            return true;
        }
        return false;
    }

    MenuItem::operator const char* () const
    {
        return m_content;
    }

    MenuItem::~MenuItem()
    {
        delete[] m_content;
        m_content = nullptr; // safe state
    }

    std::ostream& operator<<(std::ostream& os, const MenuItem& menuItem)
    {
        if (menuItem.m_content)
        {
            os << menuItem.m_content;
        }
        return os;
    }


    Menu::Menu()
    {
        m_title = nullptr;
        numItems = 0;
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            m_item[i] = nullptr;
        }
    }

    Menu::Menu(const char* menuTitle) : numItems(0)
    {
        if (menuTitle != nullptr && menuTitle[0] != '\0')
        {
            m_title = new char[strlen(menuTitle) + 1];
            strcpy(m_title, menuTitle);
        }
        else
        {
            m_title = nullptr;
        }
        for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++)
        {
            m_item[i] = nullptr;
        }
    }

    Menu::~Menu()
    {
        delete[] m_title;
        m_title = nullptr;
        for (unsigned int i = 0; i < numItems; i++)
        {
            delete m_item[i];
        }
    }

    void Menu::displayTitle() const
    {
        if (m_title != nullptr && m_title[0] != '\0')
        {
            cout << m_title << std::endl;
        }
    }

    void Menu::displayMenu() const
    {
        if (m_title != nullptr && m_title[0] != '\0')
        {
            displayTitle();
            for (unsigned int i = 0; i < numItems; i++)
            {
                cout << " " << i + 1 << "- " << m_item[i]->m_content << std::endl;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
        else
        {
            for (unsigned int i = 0; i < numItems; i++)
            {
                cout << " " << i + 1 << "- " << m_item[i]->m_content << std::endl;
            }
            cout << " 0- Exit" << endl;
            cout << "> ";
        }
    }

    unsigned int Menu::run()
    {
        displayMenu();
        unsigned int selection;
        int flag = 0;
        while (flag == 0)
        {
            if (!(cin >> selection && selection >= 0 && selection <= numItems))
            {
                cout << "Invalid Selection, try again: ";
            }
            else
                flag = 1;

            cin.clear();
            cin.ignore(1000, '\n');
        }
        return selection;
    }

    unsigned int Menu::operator~()
    {
        displayMenu();
        unsigned int selection;
        cin >> selection;

        while (selection < 0 || selection > numItems)
        {
            if (!(cin >> selection && selection >= 0 && selection <= 0))
            {
                cout << "Invalid Selection, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        return selection;
    }

    Menu& Menu::operator<<(const char* menuItemContent)
    {
        if (numItems < MAX_MENU_ITEMS)
        {
            m_item[numItems] = new MenuItem(menuItemContent);
            numItems++;
        }
        return *this;
    }

    Menu::operator bool() const
    {
        if (numItems > 0)
        {
            return true;
        }
        return false;
    }

    Menu::operator int() const
    {
        return this->numItems;
    }

    Menu::operator unsigned int() const
    {
        return this->numItems;
    }

    std::ostream& operator<<(std::ostream& os, const Menu& menu)
    {
        if (menu.m_title)
        {
            os << menu.m_title;
        }
        return os;
    }

    const char* Menu::operator[](unsigned int index) const
    {
        if (*this)
        {
            if (index > this->numItems)
            {
                return this->m_item[index % numItems]->operator const char* ();
            }
            else
            {
                return this->m_item[index]->operator const char* ();
            }
        }
        return nullptr;
    }
}