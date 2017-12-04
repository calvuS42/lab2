#include "LongInt.h"


void main() {
	string s = "100", s1 = "11";
	LongInt a(s, 10);
	cout << a;
	LongInt b(s1, 10);
	LongInt c;
	c = b;
	c = a - b;
	cout << b;
	cout << c;
	system("pause");
}