#pragma once
#include <iostream>
using namespace std;

class CDate
{
private:
	int iNgay, iThang, iNam;
public:
	CDate(int ngay = 0, int thang = 0, int nam = 0);
	friend istream& operator >>(istream& is, CDate& date);
	friend ostream& operator <<(ostream& os, CDate date);
	CDate operator +(int n);
	CDate operator -(int n);
	CDate operator ++();
	CDate operator ++(int);
	CDate operator --();
	CDate operator --(int);
	long long operator -(CDate date);
	friend long long soNgay(CDate date);

};

