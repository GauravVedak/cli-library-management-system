// Final Project
// Menu Module
// File    Menu.h
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>

namespace sdds
{
	const unsigned int MAX_MENU_ITEMS = 20;
	class MenuItem;

	class MenuItem
	{
		char* m_content;

		MenuItem();
		MenuItem(const char* itemContent);
		operator bool() const;
		operator const char* () const;
		//ostream& display(ostream& os) const;
		~MenuItem();
		friend class Menu;
		friend std::ostream& operator<<(std::ostream& os, const MenuItem& menuItem);
	};

	class Menu
	{
		char* m_title;
		MenuItem* m_item[MAX_MENU_ITEMS];
		unsigned int numItems;

	public:
		Menu();
		Menu(const char* menuTitle);
		~Menu();

		void displayTitle() const;
		void displayMenu() const;

		unsigned int run();

		unsigned int operator~();

		Menu& operator<<(const char* menuItemContent);

		operator bool() const;
		operator int() const;
		operator unsigned int() const;

		friend std::ostream& operator<<(std::ostream& os, const Menu& menu);
		const char* operator[](unsigned int index) const;
	};

}
#endif