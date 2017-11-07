#include "LongInt.h"

void main() {
	string s = "125", s1 = "7";
	LongInt a(s, 10);
	LongInt b(s, 10);
	LongInt c;
	c=a*b;
	cout << c;
	cout << b;
	system("pause");
}