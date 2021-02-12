#include "String.h"
#include "StrNum.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <bitset>
#include <cstdlib>

using namespace std;

#pragma once
#pragma warning(disable : 4996)

void StrNum::toint() {

	try {

		if (str == nullptr || !str) throw "Empty string";

		lenght = strlen(str);

		for (int i = 0; i < lenght; i++) {

			a = (int)str[i];
			itoa(a, buf, 8);

			cout << buf << endl;
		}
		
		free(buf);
	}
	catch (const char* exception) {

		std::cerr << "Error: " << exception << std::endl << " " << std::endl;
	}
}
