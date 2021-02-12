#include "String.h"
#include <cstring>
#include <iostream>
#include <fstream>

#pragma once
#pragma warning(disable : 4996)

class DateStr : public String {
public:

	DateStr() : String() { day = mounth = year = 0; }

	DateStr(const DateStr& other) : String(other) {

		try {

			if (other.day == NULL || other.mounth == NULL || other.year == NULL || ((other.mounth % 2 == 0) && (other.day > 30)) || other.mounth > 12 || other.day > 31) throw "Fields isn't solved ";

			day = other.day; mounth = other.mounth; year = other.year;
		}
		catch (const char* exception) {

			std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		}
	}

	DateStr(int day, int mounth, int year, const char* other) : String(other) {

		try {

			if (day == NULL || mounth == NULL || year == NULL || ((mounth % 2 != 0) && (day > 30)) || mounth > 12 || day > 31) throw "Fields isn't solved ";

			this->day = day; this->mounth = mounth; this->year = year;
		}
		catch (const char* exception) {

			std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		}
	}

	int setpp(int day, int mounth, int year, const char* other);

	DateStr& getpp();

	DateStr& operator=(const DateStr& other);

	friend bool operator==(const DateStr& str, const DateStr& other);

	friend std::ostream& operator<< (std::ostream& out, const DateStr& str);

	friend std::istream& operator>> (std::istream& is, DateStr& str);

	bool rd_wt_binary();

private:

	int day, mounth, year;
};
