#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class cNhanVien
{
protected:
	string maNV, hoTen, sdt, email;
	int tuoi;
	long long luongCoBan;
public:
	cNhanVien();
	virtual ~cNhanVien() {};
	virtual void nhap();
	void xuat();
	virtual long long tinhLuong() = 0;
	virtual bool getLoaiNV() = 0;
};

