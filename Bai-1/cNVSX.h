#pragma once
#include "cNhanVien.h"

class cNVSX : public cNhanVien
{
private: 
	long long luongCanBan;
	int iSoSanPham;
public:
	cNVSX();
	bool getLoaiNV() override;
	void nhap() override;
	long long getLuong();
};

