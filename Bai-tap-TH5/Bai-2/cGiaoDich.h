#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
struct date
{
	int ngay = 0, thang = 0, nam = 0;
};

class cGiaoDich
{
protected:
	string maGD;
	date ngayGD;
	long long donGia;
	double dienTich;
public:
	cGiaoDich();
	virtual ~cGiaoDich() {};
	virtual void nhap();
	void xuat();
	virtual int getLoai() = 0; //dat: 1, nha pho: 2, can ho chung cu: 3
	date getNgayGD();
	virtual long long thanhTien() = 0;
};