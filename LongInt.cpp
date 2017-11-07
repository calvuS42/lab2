#include "LongInt.h"



LongInt::LongInt()
{
	base = defbase;
}

LongInt::LongInt(int len)
{
	base = defbase;
	length = len;
	for (int i = 0; i < length; i++) {
		arr[i]
	}
}

LongInt::LongInt(string str, int base)
{
	this->base = base;
	length = str.size() / base + 1;
	arr = new int[str.size()];
	for (int i = 0; i < length; i++) {
		arr[i] = str[i] - '0';
	}
}

LongInt::LongInt(LongInt &)
{
}

LongInt LongInt::operator+(LongInt a)
{
	return LongInt();
}

LongInt LongInt::operator-(LongInt a)
{
	return LongInt();
}

LongInt LongInt::operator*(LongInt a)
{
	return LongInt();
}

LongInt LongInt::operator=(LongInt a)
{
	return LongInt();
}

LongInt::~LongInt()
{
	delete arr;
}




ostream & operator<<(ostream & stream, LongInt a)
{
	string str;
	for (int i = 0; i < a.length; i++) {
		str += a.arr[i];
	}
	stream << str << endl;
	return stream;
}

