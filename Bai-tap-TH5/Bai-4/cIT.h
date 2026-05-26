#pragma once
#include "cNhanVien.h"
class cIT : public cNhanVien
{
private:
	double gioLamThem;
public:
	cIT();
	void nhap() override;
	long long tinhLuong() override;
	bool getLoaiNV() override;
};

