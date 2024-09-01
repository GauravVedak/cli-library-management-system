// Final Project
// Publication Module
// File    Publication.h
// Author  Gaurav Amol Vedak
// -----------------------------------------------------------
// I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
/////////////////////////////////////////////////////////////////
#ifndef SENECA_PUBLICATION_H_
#define SENECA_PUBLICATION_H_
#include "Streamable.h"
#include "Date.h"
#include "Date.h"
namespace sdds
{
	class Publication : public Streamable
	{
		char* m_title{};
		char m_shelfId[5]{};
		int m_membership = 0;
		int m_libRef = -1;
	protected:
		sdds::Date m_date;


	public:
		Publication();
		Publication(const Publication& other);
		Publication& operator=(const Publication& other);
		~Publication();
		virtual void set(int member_id);
		void setRef(int value);
		void resetDate();

		virtual char type()const;
		bool onLoan()const;
		sdds::Date checkoutDate ()const;
		bool operator==(const char* title)const;
		operator const char* ()const;
		int getRef ()const;

		bool conIO(std::ios& io)const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& is);
		operator bool() const;
	};
}

#endif 

