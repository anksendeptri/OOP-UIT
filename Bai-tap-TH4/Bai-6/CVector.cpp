#include "CVector.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//constructor
CVector::CVector(int chieu, vector<double> td)
{
	iSoChieu = chieu;
	toaDo = td;
}

//operator nhap
//cach thuc: yeu cau nguoi dung nhap vao so chieu va cac toa do, neu nhap sai thi nhap lai
istream& operator>>(istream& is, CVector& vtor)
{
	cout << "Nhap so chieu > 1: ";
	while (!(is >> vtor.iSoChieu) || vtor.iSoChieu < 2)
	{
		cout << "Nhap lai! \n";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	vtor.toaDo.resize(vtor.iSoChieu);
	cout << "Nhap toa do: ";
	for (int i = 0; i < vtor.iSoChieu; i++)
		is >> vtor.toaDo[i];
	return is;
}

//operator xuat
ostream& operator<<(ostream& os, CVector vtor)
{
	os << "(";
	for (int i = 0; i < vtor.iSoChieu; i++)
	{
		os << (vtor.toaDo[i] == -0 ? 0 : vtor.toaDo[i]);
		if (i != (vtor.iSoChieu - 1))
			os << "; ";
	}
	os << ")";
	return os;
}

//operator +
//input: 1 vector khac | output: vector tong cua 2 vector
//cach thuc: cong toa do tuong ung 
CVector CVector::operator+(CVector other)
{
	if (iSoChieu != other.iSoChieu)
	{
		cout << "Khong the cong 2 vector khac so chieu!";
		return CVector();
	}
	CVector kq;
	kq.iSoChieu = iSoChieu;
	kq.toaDo.resize(iSoChieu);
	for (int i = 0; i < iSoChieu; i++)
	{
		kq.toaDo[i] = toaDo[i] + other.toaDo[i];
	}
	return kq;
}

//operator -
//input: 1 vector khac | output: vector hieu cua 2 vector
//cach thuc: tru toa do tuong ung 
CVector CVector::operator-(CVector other)
{
	if (iSoChieu != other.iSoChieu)
	{
		cout << "Khong the tru 2 vector khac so chieu!";
		return 0;
	}
	CVector kq;
	kq.iSoChieu = iSoChieu;
	kq.toaDo.resize(iSoChieu);
	for (int i = 0; i < iSoChieu; i++)
	{
		kq.toaDo[i] = toaDo[i] - other.toaDo[i];
	}
	return kq;
}

//operator * (tich vo huong)
double CVector::operator*(CVector other)
{
	if (iSoChieu != other.iSoChieu)
	{
		cout << "khong the nhan 2 vector khac so chieu!";
		return 0;
	}
	double kq = 0;
	for (int i = 0; i < iSoChieu; i++)
	{
		kq += toaDo[i] * other.toaDo[i];
	}
	return kq;
}

//operator nhan vector voi so thuc
//cach thuc: nhan tat ca toa do voi x
CVector CVector::operator*(double x)
{
	CVector kq = *this;
	for (int i = 0; i < iSoChieu; i++)
	{
		kq.toaDo[i] = toaDo[i] * x;
	}
	return kq;
}

//phuong thuc tinh do dai vector
double CVector::tinhDoDai()
{
	double kq = 0;
	for (int i = 0; i < iSoChieu; i++)
		kq += toaDo[i] * toaDo[i];
	kq = sqrt(kq);
	return kq;
}