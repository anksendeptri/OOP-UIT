#include "CDate.h"
#include <iostream>
using namespace std;

//constrctor
CDate::CDate(int ngay, int thang, int nam)
{
	iNgay = ngay;
	iThang = thang;
	iNam = nam;
}

//ham kiem tra nam nhuan
bool laNamNhuan(int nam)
{
	return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

//ham tinh so ngay trong thang
int soNgayTrongThang(int thang, int nam)
{
	if (thang == 2)
		return laNamNhuan(nam) ? 29 : 28;
	else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
		return 30;
	else
		return 31;
}

//operator nhap
istream& operator >>(istream& is, CDate& date)
{
	cout << "Nhap ngay thang nam: ";
	while(!(is >> date.iNgay >> date.iThang >> date.iNam) || date.iNgay < 1 || date.iNgay > soNgayTrongThang(date.iThang, date.iNam) || date.iThang < 1 || date.iThang > 12) 
	{
		cout << "Nhap sai. Vui long nhap lai: ";
		//xoa loi nhap
		is.clear();
		is.ignore(1000, '\n');
	}
	return is;
}

//operator xuat
ostream& operator <<(ostream& os, CDate date)
{	
	os << date.iNgay << "/" << date.iThang << "/" << date.iNam;
	return os;
}

//operator cong
//input: so ngay | output: ngay moi sau khi cong
CDate CDate::operator +(int n)
{
	CDate temp = *this;
	temp.iNgay += n;
	while (temp.iNgay > soNgayTrongThang(temp.iThang, temp.iNam))
	{
		temp.iNgay -= soNgayTrongThang(temp.iThang, temp.iNam);
		temp.iThang++;
		if(temp.iThang > 12)
		{
			temp.iThang = 1;
			temp.iNam++;
		}
	}
	return temp;
}

//operator tru
//input: so ngay | output: ngay moi sau khi tru
CDate CDate::operator -(int n)
{
	CDate temp = *this;
	temp.iNgay -= n;
	while (temp.iNgay < 1)
	{
		temp.iThang--;
		if(temp.iThang < 1)
		{
			temp.iThang = 12;
			temp.iNam--;
		}
		temp.iNgay += soNgayTrongThang(temp.iThang, temp.iNam);
	}
	return temp;
}

//operator tien to tang 1
CDate CDate::operator ++()
{
	*this = *this + 1;
	return *this;
}

//operator hau to tang 1
CDate CDate::operator ++(int)
{
	CDate temp = *this;
	*this = *this + 1;
	return temp;
}

//operator tien to giam 1
CDate CDate::operator --()
{
	*this = *this - 1;
	return *this;
}

//operator hau to giam 1
CDate CDate::operator --(int)
{
	CDate temp = *this;
	*this = *this - 1;
	return temp;
}

//ham tinh so ngay tu 1/1/0 den ngay hien tai
long long soNgay(CDate date)
{
	long long days = date.iNam * 365 + date.iNgay;
	for (int i = 1; i < date.iThang; i++)
		days += soNgayTrongThang(i, date.iNam);
	for (int i = 1; i < date.iNam; i++)
		if (laNamNhuan(i))
			days++;
	return days;
}

//operator tru 2 ngay
//input: 1 ngay | output: so ngay giua 2 ngay
//cach thuc: tinh so ngay tu 1/1/0 den ngay hien tai, sau do tru 2 so ngay voi nhau
long long CDate::operator -(CDate date)
{
	return soNgay(*this) - soNgay(date);
}