#include "LongInt.h"



LongInt::LongInt()
{
	base = defbase;
}

LongInt::LongInt(int len)
{
	base = defbase;
	length = len;
	arr = new int[len];
	for (int i = 0; i < length; i++) {
		arr[i] = 0;
	}
}

LongInt::LongInt(string& str, int base)
{
	this->base = base;
	length = str.size();
	arr = new int[str.size()];
	for (int i = 0; i < length; i++) {
		arr[i] = str[i] - '0';
	}
}

LongInt::LongInt(LongInt & numb)
{
	length = numb.length;
	base = numb.base;
	arr = new int[length];
	for (int i = 0; i < length; i++) {
		arr[i] = numb.arr[i];
	}
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


ostream & operator<<(ostream & stream, LongInt a)
{
	string str;
	for (int i = 0; i < a.length; i++) {
		str += to_string(a.arr[i]);
	}
	stream << str << endl;
	return stream;
}

