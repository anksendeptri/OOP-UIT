#include "cIT.h"

cIT::cIT()
{
	gioLamThem = 0;
}

void cIT::nhap()
{
	cNhanVien::nhap();
	cout << "Nhap gio lam them:\n";
	cin >> gioLamThem;
}

long long cIT::tinhLuong()
{
	return luongCoBan + gioLamThem * 200000;
}

bool cIT::getLoaiNV()
{
	return 0;
}