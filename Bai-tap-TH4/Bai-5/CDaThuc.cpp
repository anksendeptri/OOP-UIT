#include "CDaThuc.h"
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//constructor
CDaThuc::CDaThuc(int bac, vector<double> heSo)
{
	this->bac = bac;
	this->heSo = heSo;
}

//overload nhap
//cach thuc: nhap bac, sau do nhap he so tu bac cao den bac thap
//neu nhap sai thi yeu cau nhap lai
istream& operator >>(istream& is, CDaThuc& dt)
{
	cout << "Nhap bac cua da thuc: ";
	while (!(cin >> dt.bac) || dt.bac < 0)
	{
		cout << "Nhap sai! Vui long nhap lai bac cua da thuc: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	dt.heSo.resize(dt.bac + 1);
	for (int i = dt.bac; i >= 0; i--)
	{
		cout << "Nhap he so bac " << i << ": ";
		while (!(cin >> dt.heSo[i]))
		{
			cout << "Nhap sai! Vui long nhap lai he so x^" << i << ": ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	return is;
}

//overload xuat
/*cach thuc : xuat tu bac cao den bac thap,
neu he so = 0 thi khong xuat, 
neu he so > 0, khong phai la bac cao nhat va cac he so truoc do khong deu = 0 thi them dau + phia truoc, 
neu he so = 1 va khong phai la bac 0 thi khong xuat he so, 
neu bac > 0 thi xuat x, neu bac > 1 thi xuat ^ bac */
ostream& operator <<(ostream& os, const CDaThuc& dt)
{
	bool flag = 0;
	for (int i = dt.bac; i >= 0; i--)
	{
		if (dt.heSo[i] != 0)
		{
			if (flag && dt.heSo[i] > 0)
				os << "+";
			if (dt.heSo[i] == 1 && i > 0) {}
			else if (dt.heSo[i] == -1 && i > 0)
				os << "-"; 
			else
				os << dt.heSo[i];
			if (i > 0)
				os << "x";
			if (i > 1)
				os << "^" << i;
			flag = 1;
		}
		if (i == 0 && flag == 0)
			cout << dt.heSo[i];
	}
	return os;
}

//phương thuc tinh gia tri cua da thuc tai x
//input: 1 so thuc x
//output: gia tri cua da thuc tai x
double CDaThuc::tinhGiaTri(double x)
{
	double giaTri = 0;
	for (int i = 0; i <= bac; i++)
	{
		giaTri += heSo[i] * pow(x, i);
	}
	return giaTri;
}

//overload toan tu cong 
//input: 1 da thuc dt 
//output: 1 da thuc moi la tong cua da thuc hien tai va da thuc dt
//cach thuc: tim bac cao nhat cua 2 da thuc, sau do cong he so tuong ung cua 2 da thuc, neu bac nao khong co thi lay he so = 0
CDaThuc CDaThuc::operator +(const CDaThuc& dt)
{
	int maxBac = max(bac, dt.bac);
	vector<double> tong;
	tong.resize(maxBac + 1);
	for (int i = 0; i <= maxBac; i++)
	{
		double hs1 = (i <= bac) ? heSo[i] : 0;
		double hs2 = (i <= dt.bac) ? dt.heSo[i] : 0;	
		tong[i] = hs1 + hs2;
	}
	return CDaThuc(maxBac, tong);
}

//overload toan tu tru
//input: 1 da thuc dt
//output: 1 da thuc moi la hieu cua da thuc hien tai va da thuc dt
//cach thuc: tim bac cao nhat cua 2 da thuc, sau do tru he so tuong ung cua 2 da thuc, neu bac nao khong co thi lay he so = 0
CDaThuc CDaThuc::operator -(const CDaThuc& dt)
{
	int maxBac = max(bac, dt.bac);
	vector<double> hieu;
	hieu.resize(maxBac + 1);
	for (int i = 0; i <= maxBac; i++)
	{
		double hs1 = (i <= bac) ? heSo[i] : 0;
		double hs2 = (i <= dt.bac) ? dt.heSo[i] : 0;
		hieu[i] = hs1 - hs2;
	}
	return CDaThuc(maxBac, hieu);
}