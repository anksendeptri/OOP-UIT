#include"cDaThuc.h"
#include<iostream>
#include<vector>
using namespace std;

//constructor mac dinh va co tham so
cDaThuc::cDaThuc(int b)
{
	bac = b;
	heSo.resize(bac + 1);
}

//phuong thuc tinh gia tri da thuc tai x
//input: 1 gia tri x
//output: gia tri da thuc tai x
//cach thuc: thay x vao da thuc roi tinh toan
double cDaThuc::tinhGiaTri(double x)
{
	double kq = 0;
	for (int i = 0; i <= bac; i++)
		kq += heSo[i] * pow(x, i);
	return kq;
}	

//phuong thuc nhap da thuc
//cach thuc: nhap bac cua da thuc, sau do nhap he so tu bac cao den bac thap
//neu nhap sai thi nhap lai
void cDaThuc::nhap()
{
	cout << "Nhap bac cua da thuc: ";
	while (!(cin >> bac) || bac < 0)
	{
		cout << "Nhap sai! Vui long nhap lai bac cua da thuc: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
	heSo.resize(bac + 1);
	for (int i = bac; i >= 0; i--)
	{
		cout << "Nhap he so x^" << i << ": ";
		while (!(cin >> heSo[i]))
		{
			cout << "Nhap sai! Vui long nhap lai he so x^" << i << ": ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

//phuong thuc xuat da thuc
//cach thuc: xuat he so tu bac cao den bac thap,
//neu he so bang 0 thi bo qua,
//neu he so duong va khong phai la bac cao nhat thi them dau + truoc he so
void cDaThuc::xuat()
{
	if (bac == 0 && heSo[0] == 0)
	{
		cout << "0";
		return;
	}

	for (int i = bac; i >= 0; i--)
	{
		if (heSo[i] != 0)
		{
			if (i != bac && heSo[i] > 0)
				cout << "+";
			if (i == 0)
				cout << heSo[i];
			else if (i == 1)
				cout << heSo[i] << "x";
			else
				cout << heSo[i] << "x^" << i;
		}
	}
}
//phuong thuc cong hai da thuc
//input: 1 da thuc
//output: 1 da thuc moi la ket qua cua phep cong
//cach thuc: cong he so tuong ung cua hai da thuc, neu bac khac nhau thi lay he so cua da thuc co bac nho hon bang 0
cDaThuc cDaThuc::congDaThuc(cDaThuc dt)
{
	cDaThuc kq(max(bac, dt.bac));
	for (int i = 0; i <= kq.bac; i++)
	{
		double hs1 = (i <= bac) ? heSo[i] : 0;
		double hs2 = (i <= dt.bac) ? dt.heSo[i] : 0;
		kq.heSo[i] = hs1 + hs2;
	}
	return kq;
}

//phuong thuc tru hai da thuc
//input: 1 da thuc 
//output: 1 da thuc moi la ket qua cua phep tru
//cach thuc: da thuc this tru cho da thuc truyen vao, neu bac khac nhau thi lay he so cua da thuc co bac nho hon bang 0
cDaThuc cDaThuc::truDaThuc(cDaThuc dt)
{
	cDaThuc kq(max(bac, dt.bac));
	for (int i = 0; i <= kq.bac; i++)
	{
		double hs1 = (i <= bac) ? heSo[i] : 0;
		double hs2 = (i <= dt.bac) ? dt.heSo[i] : 0;
		kq.heSo[i] = hs1 - hs2;
	}
	return kq;
}