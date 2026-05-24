#pragma once
#include "cGiaoDich.h"
class cCanHo : public cGiaoDich
{
private:
	string maCan;
	int viTriTang;
public:
	cCanHo();
	void nhap() override;
	long long thanhTien() override;
	int getLoai() override;
};

