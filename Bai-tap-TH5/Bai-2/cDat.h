#pragma once
#include "cGiaoDich.h"
class cDat : public cGiaoDich
{
private:
	char loaiDat;
public:
	cDat();
	void nhap() override;
	long long thanhTien() override;
	int getLoai() override;
};

