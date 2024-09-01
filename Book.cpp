// Final Project
// Book Module
// File    Book.cpp
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
#include "Lib.h"
#include "Book.h"
using namespace std;
namespace sdds
{
	Book::Book()
	{
		m_authorName = nullptr;
	}
	Book::Book(const Book& B) : Publication(B)
	{
		m_authorName = nullptr;
		*this = B;
	}
	Book& Book::operator=(const Book& B)
	{
		if (this != &B)
		{
			Publication::operator=(B);
			delete[] m_authorName;

			if (B.m_authorName != nullptr)
			{
				m_authorName = new char[strlen(B.m_authorName) + 1];
				strcpy(m_authorName, B.m_authorName);
			}
		}
		else
			m_authorName = nullptr;
		return *this;
	}
	Book::~Book()
	{
		delete[] m_authorName;
		m_authorName = nullptr;
	}


	char Book::type()const
	{
		return 'B';
	}
	std::ostream& Book::write(std::ostream& os) const
	{
		Publication::write(os);

		if (conIO(os))
		{
			os << ' ';
			if (m_authorName and strlen(m_authorName) > SENECA_AUTHOR_WIDTH)
			{
				os.write(m_authorName, SENECA_AUTHOR_WIDTH);
			}
			else
			{
				os.width(SENECA_AUTHOR_WIDTH);
				os.setf(ios::left);
				os << this->m_authorName;
				os.unsetf(ios::left);
			}
			os << " |";
		}
		else
		{
			os << '\t' << m_authorName;
		}
		return os;
	}
	std::istream& Book::read(std::istream& is)
	{
		char authorNameInput[257]{};
		Publication::read(is);
		delete[] m_authorName;
		m_authorName = nullptr;

		if (conIO(is))
		{
			is.ignore(3000, '\n');

			cout << "Author: ";
			is.getline(authorNameInput, 257, '\n');
		}
		else
		{
			is.ignore();
			is.get(authorNameInput, 257, '\n');
		}

		m_authorName = new char[strlen(authorNameInput) + 1];
		strcpy(m_authorName, authorNameInput);

		return is;
	}
	void Book::set(int memberId)
	{
		Publication::set(memberId);
		resetDate();

	}
	Book::operator bool() const
	{
		if (m_authorName != nullptr && m_authorName[0] != '\0' and Publication::operator bool() == true)
		{
			return true;
		}
		return false;
	}

}