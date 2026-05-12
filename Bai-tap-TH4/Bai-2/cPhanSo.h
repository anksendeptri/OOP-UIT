#pragma once
#include <iostream>
using namespace std;

class cPhanSo
{
private: 
	int iTu;
	int iMau;
public:
	cPhanSo(int tu = 0, int mau = 1);
	friend istream& operator >>(istream& is, cPhanSo& ps);
	friend ostream& operator <<(ostream& os, cPhanSo ps);
	cPhanSo operator +(cPhanSo ps);
	cPhanSo operator -(cPhanSo ps);
	cPhanSo operator *(cPhanSo ps);
	cPhanSo operator /(cPhanSo ps);
	bool operator ==(cPhanSo ps);
	bool operator >(cPhanSo ps);
	bool operator <(cPhanSo ps);
};

