#include <cstring>
#include <iostream>
#include <fstream>
#include <clocale>
#include <bitset>
#include "String.h"
#include "StrNum.h"
#include "DateStr.h"


#pragma warning(disable : 4996)

using namespace std;


bool test_original_file(String& a) {

	const char* s = "test_Test-tEsT";
	bool rez = NULL;

	try {

		if (a.getpp() == nullptr && !a.getpp()) { throw "Test hasn't been complited "; }
		else {

			fstream fs;

			fs.open("txt.txt", fstream::in | fstream::out | fstream::app);

			if (!fs.is_open()) {

				cout << "error of open" << endl;
			}
			else {

				cout << "file is open" << endl;

				fs << a;
			}
			fs.close();


			fs.open("txt.txt", fstream::in | fstream::out | fstream::app);

			if (!fs.is_open()) {

				cout << "error of open" << endl;
			}
			else {

				cout << "file is open" << endl;

				int len = strlen(a.getpp());

				fs.seekg(-len - 2, ios::end);
				fs >> a;
				cout << a;
			}
			fs.close();

			if (a == s) {

				rez = true;
				cout << "Result test: " << "test original is OK" << endl << endl << endl << endl << "***" << endl;
			}
			else {

				rez = false;
				cout << "Result test: " << "test original is BAD" << endl << endl << endl << endl << "***" << endl;
			}
		}

		return (rez) ? true : false;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		return 0;
	}
}


bool test_binary_file(String& a) {

	const char* s = "test_Test-tEsT";
	bool rez;

	try {

		if (a.getpp() == nullptr && !a.getpp()) { throw "Test hasn't been complited "; }
		else {

			if (a == s && a.read_wrire_binary()) {

				rez = true;
				cout << "Result test: " << "test binary is OK" << endl << endl << endl << endl << "***" << endl;
			}
			else {

				rez = false;
				cout << "Result test: " << "test binary is BAD" << endl << endl << endl << endl << "***" << endl;
			}
		}

		return (rez) ? true : false;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		return 0;
	}
}


bool test_sum(String& a, const char* b) {

	const char* s = "abcdef";
	bool rez;

	try {

		if (b == nullptr && !b) throw "Test hasn't been complited ";


		cout << "First string: " << a.getpp() << endl << "Second string: " << b << endl << "The line that should turn out: " << s << endl;

		if (strcmp(a.sum(b), s) == 0) {
			rez = true;
			cout << "Result test: " << "test sum is OK" << endl << endl << endl << endl << "***" << endl;
		}
		else {
			rez = false;
			cout << "Result test: " << "test sum is BAD" << endl << endl << endl << endl << "***" << endl;
		}

		return (rez) ? true : false;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		return 0;
	}
}


bool test_search(String& a, const char* b) {

	bool rez;

	try {

		if (b == NULL && !b) throw "Test hasn't been complited ";


		cout << "First string: " << a.getpp() << endl << "Second string: " << b << endl;

		if (a.search(b)) {
			rez = true;
			cout << "Result test: " << "test search is OK" << endl << endl << endl << endl << "***" << endl;
		}
		else {
			rez = false;
			cout << "Result test: " << "test search is BAD" << endl << endl << endl << endl << "***" << endl;
		}

		return (rez) ? true : false;
	}

	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
		return 0;
	}
}


bool test_operator_1(String& myfield, String& other) {

	const char* s = "asdfas";
	bool rez;

	try {

		if (myfield.getpp() == nullptr && !myfield.getpp() && other.getpp() == nullptr && !other.getpp()) throw "Test hasn't been complited ";

		cout << "First string: " << myfield.getpp() << endl << "Second string: " << other.getpp() << endl << "The line that should turn out: " << s << endl;


		if ((myfield.operator+(other)) == s) {
			rez = true;
			cout << "Result test: " << "test 1 is OK" << endl << endl << endl << endl << "***" << endl;
		}
		else {
			rez = false;
			cout << "Result test: " << "test 1 is BAD" << endl << endl << endl << endl << "***" << endl;
		}

		return (rez) ? true : false;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << endl << " " << endl;
		return 0;
	}
}


bool test_operator_2(String& myfield, const char* other) {

	const char* s = "asdf";
	bool rez;

	try {

		if (myfield.getpp() == nullptr && !myfield.getpp() && other == nullptr && !other) throw "Test hasn't been complited ";

		cout << "First string: " << myfield.getpp() << endl << "Second string: " << other << endl << "The line that should turn out: " << s << endl;


		if (myfield.operator+(other) == s) {
			rez = true;
			cout << "Result test: " << "test 2 is OK" << endl << endl << endl << endl << "***" << endl;
		}
		else {
			rez = false;
			cout << "Result test: " << "test 2 is BAD" << endl << endl << endl << endl << "***" << endl;
		}

		return (rez) ? true : false;
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << endl;
		return 0;
	}
}


int main() {	
	
	StringNumber a;
	StringNumber b("qwerty");
	
	
}
