#include "String.h"
#include <cstring>
#include <iostream>
#include <fstream>

#pragma once
#pragma warning(disable : 4996)

class StrNum: public String {
public:

	StrNum() : String() {}

	StrNum(const StrNum& other) : String(other) {}

	StrNum(const char* other) : String(other) {}

	void toint();



private:

	char* buf = new char[64];
	int a;
};