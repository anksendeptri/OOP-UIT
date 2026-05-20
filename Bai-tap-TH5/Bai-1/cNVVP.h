#pragma once
#include "cNhanVien.h"
class cNVVP : public cNhanVien
{
private:
	int iSoNgayLamViec;
public: 
	cNVVP();
	bool getLoaiNV() override;
	void nhap() override;
	long long getLuong() override;
};

