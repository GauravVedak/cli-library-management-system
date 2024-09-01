// Final Project
// Book Module
// File    Book.h
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SENECA_BOOK_H_
#define SENECA_BOOK_H_
#include "Publication.h"
namespace sdds
{
	class Book : public Publication
	{
		char* m_authorName;
	public:
		Book();
		Book(const Book& B);
		Book& operator=(const Book& B);
		~Book();
		virtual char type()const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		void set(int memberId);
		operator bool() const;
	};
}

#endif

