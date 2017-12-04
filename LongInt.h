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
	LongInt operator* (int a);
	LongInt Karatzuba(LongInt a, LongInt b);
	void to_same(LongInt a);
	LongInt operator/ (LongInt a);
	void operator= (LongInt a);
	void operator= (int a);
	friend ostream& operator << (ostream& stream, LongInt a);
protected:
	int* arr;
	int length;
	int base;
};

	