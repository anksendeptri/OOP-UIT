#include "cCanHo.h"

cCanHo::cCanHo()
{
	viTriTang = 0;
}

void cCanHo::nhap()
{
	cGiaoDich::nhap();
	cout << "Nhap ma can ho:\n";
	cin >> maCan;
	cout << "Nhap vi tri tang:\n";
	cin >> viTriTang;
}

long long cCanHo::thanhTien()
{
	if (viTriTang == 1)
		return dienTich * donGia * 2;
	else if (viTriTang >= 15)
		return dienTich * donGia * 1.2;
	else
		return dienTich * donGia;
}

int cCanHo::getLoai()
{
	return 3;
}