#pragma once
#include "cGiaoDich.h"
class cNhaPho : public cGiaoDich
{
private:
	bool loaiNha; //thuong: 0, cao cap: 1
public:
	cNhaPho();
	void nhap() override;
	long long thanhTien() override;
	int getLoai() override;
};

