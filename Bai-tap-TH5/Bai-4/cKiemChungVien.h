#pragma once
#include "cNhanVien.h"
class cKiemChungVien : public cNhanVien
{
private:
	int soLoi;
public:
	cKiemChungVien();
	void nhap() override;
	long long tinhLuong() override;
	bool getLoaiNV();
};

