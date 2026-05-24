#include "cDat.h"

cDat::cDat()
{
	loaiDat = '\0';
}

void cDat::nhap()
{
	cGiaoDich::nhap();
	cout << "Nhap loai dat (A, B, C):\n";
	cin >> loaiDat;
}

long long cDat::thanhTien()
{
	if (loaiDat == 'A')
		return	dienTich * donGia * 1.5;
	else
		return dienTich * donGia;
}

int cDat::getLoai()
{
	return 1;
}