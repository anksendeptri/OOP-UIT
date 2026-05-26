#pragma once
#include "cSinhVien.h"
class cCaoDang : public cSinhVien
{
private:
	double diemTN;
public:
	cCaoDang();
	void nhap() override;
	bool getLoaiSV() override;
	bool totNghiep() override;
};

