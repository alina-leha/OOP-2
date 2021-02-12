#include "String.h"
#include "DateStr.h"
#include <cstring>
#include <iostream>
#include <fstream>

#pragma once
#pragma warning(disable : 4996)


int DateStr::setpp(int day, int mounth, int year, const char* other) {

	try {

		if (day == NULL || mounth == NULL || year == NULL || ((mounth % 2 != 0) && (day > 30)) || mounth > 12 || day > 31) throw "Fields isn't set ";

		String::setpp(other);
		this->day = day; this->mounth = mounth; this->year = year;
		
		return 1;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		return 0;
	}
	
}


DateStr& DateStr::getpp() {

	try {

		if (day == NULL || mounth == NULL || year == NULL || ((mounth % 2 != 0) && (day > 30)) || mounth > 12 || day > 31 || str == nullptr || !str) throw "Obj can't get";

		String::getpp();

		return *this;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
	}
}


DateStr& DateStr::operator=(const DateStr& other) {
	
	try {

		if (other.str == NULL || !other.str || other.day == NULL || other.mounth == NULL || other.year == NULL || ((other.mounth % 2 != 0) && (other.day > 30)) || other.mounth > 12 || other.day > 31) throw "Operator = didn't work ";

		day = mounth = year = 0;
		delete[]this->str;

		strcpy(str, other.str);
		day = other.day; mounth = other.mounth; year = other.year;

		return *this;
	}

	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
	}
}


bool DateStr::rd_wt_binary() {

	try {

		if (str == nullptr || !str || day == NULL || mounth == NULL || year == NULL || ((mounth % 2 != 0) && (day > 30)) || mounth > 12 || day > 31) { throw "Binary hasn't been complited "; }
		else {

			std::fstream fs;

			fs.open("dat.dat", std::fstream::in | std::fstream::out | std::fstream::app | std::fstream::binary);

			if (!fs.is_open()) {

				std::cout << "error of open" << std::endl;
				return 0;
			}
			else {

				std::cout << "file is open" << std::endl;

				fs << str << day << mounth << year;

				return 1;
			}
			fs.close();


			fs.open("dat.dat", std::fstream::in | std::fstream::out | std::fstream::app | std::fstream::binary);

			if (!fs.is_open()) {

				std::cout << "error of open" << std::endl;
				return 0;
			}
			else {

				std::cout << "file is open" << std::endl;

				int len = strlen(str);

				fs.seekg(-len - 2, std::ios::end);

				fs >> str >> day >> mounth >> year;
				std::cout << year << mounth << day << str;

				return 1;
			}
			fs.close();

		}
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		return 0;
	}
}


bool operator==(const DateStr& my, const DateStr& other) {
	
	bool flag = false;

	try {

		if (other.str == NULL || !other.str || my.str == NULL || !my.str || other.day == NULL || other.mounth == NULL || other.year == NULL || ((other.mounth % 2 != 0) && (other.day > 30)) || my.day == NULL || my.mounth == NULL || my.year == NULL || ((my.mounth % 2 != 0) && (my.day > 30))) throw "Operator == didn't work ";

		if ((my.day == other.day && my.mounth == other.mounth && my.year == other.year) && (strstr(my.str, other.str) == &my.str[0] && strlen(my.str) == strlen(other.str))) flag = true;
		return (flag) ? true : false;
	}

	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
	}
}


std::ostream& operator<<(std::ostream& out, const DateStr& str) {
	
	try {

		if (str.str == nullptr || !str.str || str.day == NULL || str.mounth == NULL || str.year == NULL || ((str.mounth % 2 != 0) && (str.day > 30))) throw "Empty string";

		out << str.str << std::endl << str.day << std::endl << str.mounth << std::endl << str.year << std::endl;
		return out;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
	}
}


std::istream& operator>>(std::istream& is, DateStr& str) {
	
	try {

		if (str.str == nullptr || !str.str || str.day == NULL || str.mounth == NULL || str.year == NULL || ((str.mounth % 2 != 0) && (str.day > 30))) throw "Empty string";

		is >> str.str >> str.day >> str.mounth >> str.year;
		return is;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
	}
}
