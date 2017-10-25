#pragma once
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class LongInt
{
public:
	LongInt();
	LongInt(string);
	LongInt(LongInt&);
	friend const LongInt operator+ (LongInt a, LongInt b);
	friend const LongInt operator- (LongInt a, LongInt b);
	friend const LongInt operator* (LongInt a, LongInt b);
	friend const LongInt operator/ (LongInt a, LongInt b);
	//friend const LongInt operator= (LongInt a, LongInt b);
	friend ostream& operator << (ostream& stream, LongInt a);
	friend ostream& operator >> (ostream& stream, LongInt a);

private:
	vector <int> Number;
	int base;
	int n;
};

	