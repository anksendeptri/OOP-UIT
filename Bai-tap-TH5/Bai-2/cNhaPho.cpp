#include "cNhaPho.h"

cNhaPho::cNhaPho()
{
	loaiNha = 0;
}

void cNhaPho::nhap()
{
	cGiaoDich::nhap();
	cout << "Nhap loai nha (thuong: 0, cao cap: 1):\n";
	cin >> loaiNha;
}

long long cNhaPho::thanhTien()
{
	if (loaiNha)
		return dienTich * donGia;
	else
		return dienTich * donGia * 0.9;
}

int cNhaPho::getLoai()
{
	return 2;
}