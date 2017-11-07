#include "LongInt.h"

void main() {
	string s = "123124141415";
	LongInt a(s, 10);
	LongInt b(s, 1024);
	cout << a;
	cout << b;
	system("pause");
}