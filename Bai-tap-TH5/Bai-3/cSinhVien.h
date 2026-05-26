#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class cSinhVien
{
protected:
	string maSV, hoTen, diaChi;
	int soTinChi;
	double diemTB;
public:
	cSinhVien();
	virtual ~cSinhVien() {};
	virtual void nhap();
	void xuat();
	virtual bool totNghiep() = 0;
	double getDiemTB();
	virtual bool getLoaiSV() = 0; //cao dang: 0, dai hoc: 1
};

