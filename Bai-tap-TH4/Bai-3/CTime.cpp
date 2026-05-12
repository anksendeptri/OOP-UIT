#include "CTime.h"
#include <iostream>
using namespace std;

CTime::CTime(int h, int m, int s)
{
	iGio = h;
	iPhut = m;
	iGiay = s;
}

istream& operator >>(istream &is, CTime &t)
{
	cout << "Pham vi: 0:00:00 - 23:59:59" << endl;
	cout << "Nhap gio phut giay: ";
	while (!(is >> t.iGio >> t.iPhut >> t.iGiay) || t.iGio < 0 || t.iGio > 23 || t.iPhut < 0 || t.iPhut > 59 || t.iGiay < 0 || t.iGiay > 59) 
	{
		cout << "Nhap sai, vui long nhap lai: ";
		is.clear();
		is.ignore(1000, '\n');
	}
	return is;
}

ostream& operator <<(ostream &os, const CTime &t)
{
	os << t.iGio << ":"; 
	os << (t.iPhut < 10 ? "0" : "") << t.iPhut << ":";
	os << (t.iGiay < 10 ? "0" : "") << t.iGiay;
	return os;
}

CTime CTime::operator + (int s)
{
	iGiay += s;
	if (iGiay >= 60) 
	{
		iPhut += iGiay / 60;
		iGiay %= 60;
	}
	if (iPhut >= 60) 
	{
		iGio += iPhut / 60;
		iPhut %= 60;
	}
	if (iGio >= 24) 
	{
		iGio %= 24;
	}
	return *this;
}

CTime CTime::operator - (int s)
{
	iGiay -= s;
	if (iGiay < 0) 
	{
		iPhut += (iGiay - 59) / 60;
		iGiay = (iGiay % 60 + 60) % 60;
	}
	if (iPhut < 0) 
	{
		iGio += (iPhut - 59) / 60;
		iPhut = (iPhut % 60 + 60) % 60;
	}
	if (iGio < 0) 
	{
		iGio = (iGio % 24 + 24) % 24;
	}
	return *this;
}

CTime CTime::operator ++()
{
	return *this + 1;
}

CTime CTime::operator ++(int)
{
	CTime t = *this;
	++*this;
	return t;
}

CTime CTime::operator --()
{
	return *this - 1;
}

CTime CTime::operator --(int)
{
	CTime t = *this;
	--*this;
	return t;
}