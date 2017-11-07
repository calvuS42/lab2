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
	length = ceil(str.size() * sizeof(int) / sizeof(base));
	int base_length = sizeof(base) / sizeof(int) - '\0';
	arr = new int[length];
	int* s = new int[length];
	while (str.size() % base_length != 0) { str = "0" + str; }
	for (int i = 0 ; i < length; i+= base_length) {
		string k = str.substr(i, base_length);
		arr[i] = atoi(k.c_str()) ;
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

LongInt LongInt::operator+(LongInt b)
{
	int newLen = 0;
	(length > b.length) ? (newLen = length) : (newLen = b.length);
	if (arr[0] + b.arr[0] > base) newLen++;

	LongInt res(newLen); res.base = base;

	for (int i = newLen - 1, ia = length - 1, ib = b.length - 1; i >= 0; i--, ia--, ib--) {
		if (ia >= 0 && ib >= 0)
			res.arr[i] += arr[ia] + b.arr[ib];

		else if (ia < 0 && ib >= 0)
			res.arr[i] += b.arr[ib];

		else res.arr[i] += arr[ia];

		int q = i;
		while (res.arr[q] >= res.base && q) {
			res.arr[q - 1] += res.arr[q] / res.base;
			res.arr[q]+= res.arr[q] % res.base;
			q--;
		}

	}

	if (res.arr[0] >= res.base) {
		newLen++;
		LongInt newres(newLen); newres.base = res.base;
		for (int i = 0; i < newLen; i++) 
			newres.arr[i] = res.arr[i - 1];
		newres.arr[1] = newres.arr[1] % newres.base;
		newres.arr[0] = newres.arr[1] / newres.base;
		res = newres;
	}
	while (res.arr[0] == 0 && res.length > 1) {
		res.length--;
		for (int i = 0; i < res.length; i++) {
			res.arr[i] = res.arr[i + 1];
		}
	}
	return res;
}

LongInt LongInt::operator-(LongInt a)
{
	return LongInt();
}

LongInt LongInt::operator*(LongInt a)
{
	int len = 0;;
	(length > a.length) ? len = length : len = a.length;
	LongInt res(len * 2);
	for (int i = 0; i < len / 2; ++i) {
		for (int j = 0; j < len / 2; ++j) {
			res.arr[i + j] += arr[i] * a.arr[j];
		}
	}
	return res;
}

LongInt LongInt::Karatzuba(LongInt a, LongInt b)
{
	LongInt res(a.length + b.length);
	if (a.length < minlen || b.length < minlen) {
		res = a*b;
		return res;
	}
	else
	{
		a.to_same(b);
		LongInt a0, a1(a), b0, b1(b);
		a1.length = (a.length + 1) / 2;
		a0.arr = a.arr + a1.length;
		a0.length = a.length / 2;
		b1.length = (b.length + 1) / 2;
		b0.arr = b.arr + b1.length;
		b0.length = b.length / 2;
		int t = a0.length;


		LongInt a0_plus_a1(a0 + a1); // need to add or subs, hope will work
		LongInt b0_plus_b1(b0 + b1);
		LongInt add_all = Karatzuba(a0_plus_a1, b0_plus_b1);
		LongInt a0_mul_b0 = Karatzuba(a0, b0);
		LongInt a1_mul_b1 = Karatzuba(a1, b1);
		LongInt minus = (add_all - a0_mul_b0) - a1_mul_b1;

		for (int i = 0; i<t; i++) {
			minus.length++;
			minus.arr[minus.length - 1] = 0;
		}

		for (int i = 0; i<2 * t; i++) {
			a1_mul_b1.length++;
			a1_mul_b1.arr[a1_mul_b1.length - 1] = 0;
		}

		res = a0_mul_b0 + minus + a1_mul_b1;
	}
	return LongInt();
}

void LongInt::to_same(LongInt a)
{
	if (length == a.length)return;
	if (length>a.length) {
		int t = a.length;
		a.length = length;
		for (int i = 0; i<t; i++) {
			a.arr[a.length - 1 - i] = a.arr[t - 1 - i];
		}
		for (int i = 0; i<length - t; i++) a.arr[i] = 0;
	}
	else
	{
		int t = length;
		length = a.length;
		for (int i = 0; i<t; i++) {
			arr[length - 1 - i] = arr[t - 1 - i];
		}
		for (int i = 0; i<a.length - t; i++) arr[i] = 0;
	}
}

LongInt LongInt::operator/(LongInt a)
{
	return LongInt();
}

void LongInt::operator=(LongInt a)
{
	base = a.base;
	length = a.length;
	arr = new int[length];
	for (int i = 0; i < length; i++) {
		arr[i] = a.arr[i];
	}
}

void LongInt::operator=(int a)
{
	LongInt b(to_string(a), base);
	*this = b;
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

