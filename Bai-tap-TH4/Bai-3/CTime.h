#pragma once
#include <iostream>
using namespace std;	

class CTime
{
private:
	int iGio, iPhut, iGiay;
public:
	CTime(int = 0, int = 0, int = 0);
	friend istream& operator >>(istream&, CTime&);
	friend ostream& operator <<(ostream&, const CTime&);
	CTime operator + (int);
	CTime operator - (int);
	CTime operator ++();
	CTime operator ++(int);
	CTime operator --();
	CTime operator --(int);
};

