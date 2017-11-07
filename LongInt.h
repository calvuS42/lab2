#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

const int defbase = 10;
const int maxlen = 1000;
const int minlen = 4;


class LongInt
{
public:
	LongInt();
	LongInt(int len);
	LongInt(string& str, int base);
	LongInt(LongInt&);
	LongInt operator+ (LongInt a);
	LongInt operator- (LongInt a);
	LongInt operator* (LongInt a);
	//LongInt operator/ (LongInt a);
	LongInt operator= (LongInt a);
	friend ostream& operator << (ostream& stream, LongInt a);
protected:
	int* arr;
	int length;
	int base;
};

	