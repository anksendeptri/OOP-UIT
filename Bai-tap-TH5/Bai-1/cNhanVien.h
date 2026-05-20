#pragma once
#include <string>
using namespace std;

struct date
{
	int day, month, year;
};


class cNhanVien
{
protected:
	string sHoTen;
	date sNgaySinh;
	long long luong;
public:
	cNhanVien();
	virtual void nhap();
	void xuat();
	long long tinhTrongSoNgaySinh();
	virtual bool getLoaiNV() = 0;
	virtual long long getLuong() = 0; 
};

