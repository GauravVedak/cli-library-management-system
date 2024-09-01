// Final Project
// LibApp Module
// File    LibApp.h
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SENECA_LIBAPP_H
#define SENECA_LIBAPP_H
#include "Publication.h"
#include "Lib.h"
#include "Menu.h"
namespace sdds {
	class LibApp
	{
		bool m_changed;

		Menu m_mainMenu;

		Menu m_exitMenu;


		char m_filename[256];

		Publication* m_ppa[SENECA_LIBRARY_CAPACITY];

		int m_nolp;

		int m_llrn; 

		Menu m_pubTypeMenu;

		bool confirm(const char* message);
		void load();
		void save();
		int search(int mode);

		Publication* getPub(int libRef);
		void newPublication();
		void removePublication();
		void checkOutPub();
		void returnPub();



	public:
		void run();

		LibApp(const char* filename);


		~LibApp();

	};
}
#endif 



