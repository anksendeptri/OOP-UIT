#include "cPhanSo.h"
#include <iostream>
#include <numeric>

using namespace std;

// Constructor
cPhanSo::cPhanSo(int tu, int mau)
{
	iTu = tu;
	iMau = mau;
}

// operator nhap
istream& operator >>(istream& is, cPhanSo& ps)
{
	cout << "Nhap tu so va mau so: ";
	while (!(is >> ps.iTu >> ps.iMau) || ps.iMau == 0)
	{
		cout << "Nhap lai! \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	return is;
}

// operator xuat
ostream& operator <<(ostream& os, cPhanSo ps)
{
	//rut gon phan so
	int ucln = gcd(ps.iTu, ps.iMau);
	ps.iTu /= ucln;
	ps.iMau /= ucln;

	//chinh dau 
	if (ps.iMau < 0)
	{
		ps.iTu = -ps.iTu;
		ps.iMau = -ps.iMau;
	}
	os << ps.iTu;
	if (ps.iMau != 1)
		os << "/" << ps.iMau;


	return os;
}

// operator cong
//input: 1 phan so ps | output: 1 phan so la tong cua 2 phan so
//cach thuc: a/b + c/d = (a*d + b*c) / (b*d)
cPhanSo cPhanSo::operator +(cPhanSo ps)
{
	cPhanSo temp;
	temp.iTu = iTu * ps.iMau + ps.iTu * iMau;
	temp.iMau = iMau * ps.iMau;
	return temp;
}

// operator tru
//input: 1 phan so ps | output: 1 phan so la hieu cua 2 phan so
//cach thuc: a/b - c/d = (a*d - b*c) / (b*d)
cPhanSo cPhanSo::operator -(cPhanSo ps)
{
	cPhanSo temp;
	temp.iTu = iTu * ps.iMau - ps.iTu * iMau;
	temp.iMau = iMau * ps.iMau;
	return temp;
}

// operator nhan
//input: 1 phan so ps | output: 1 phan so la tich cua 2 phan so
//cach thuc: a/b * c/d = (a*c) / (b*d)
cPhanSo cPhanSo::operator *(cPhanSo ps)
{
	cPhanSo temp;
	temp.iTu = iTu * ps.iTu;
	temp.iMau = iMau * ps.iMau;
	return temp;
}

// operator chia
//input: 1 phan so ps | output: 1 phan so la thuong cua 2 phan so
//cach thuc: a/b / c/d = (a*d) / (b*c)
cPhanSo cPhanSo::operator /(cPhanSo ps)
{
	if (ps == cPhanSo())
		cout << "khong the chia cho "; return cPhanSo();
	cPhanSo temp;
	temp.iTu = iTu * ps.iMau;
	temp.iMau = iMau * ps.iTu;
	return temp;
}

// operator bang
//input: 1 phan so ps | output: true neu 2 phan so bang nhau, nguoc lai la false
//cach thuc: a/b == c/d <=> a*d == b*c
bool cPhanSo::operator ==(cPhanSo ps)
{
	return (iTu * ps.iMau == iMau * ps.iTu);
}

// operator lon hon
//input: 1 phan so ps | output: true neu phan so hien tai lon hon ps, nguoc lai la false
//cach thuc: a/b > c/d <=> a*d > b*c
bool cPhanSo::operator >(cPhanSo ps)
{
	return (iTu * ps.iMau > iMau * ps.iTu);
}

// operator nho hon
//input: 1 phan so ps | output: true neu phan so hien tai nho hon ps, nguoc lai la false
//cach thuc: a/b < c/d <=> a*d < b*c
bool cPhanSo::operator <(cPhanSo ps)
{
	return (iTu * ps.iMau < iMau * ps.iTu);
}

