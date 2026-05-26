#pragma once
#include "cSinhVien.h"
class cDaiHoc : public cSinhVien
{
private:
	string tenLuanVan;
	double diemLuanVan;
public:
	cDaiHoc();
	void nhap() override;
	bool getLoaiSV() override;
	bool totNghiep() override;
};

