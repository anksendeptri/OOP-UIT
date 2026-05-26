#include "cKiemChungVien.h"
cKiemChungVien::cKiemChungVien()
{
	soLoi = 0;
}

void cKiemChungVien::nhap()
{
	cNhanVien::nhap();
	cout << "Nhap so loi da phat hien:\n"; 
	cin >> soLoi;
}

long long cKiemChungVien::tinhLuong()
{
	return luongCoBan + soLoi * 50000;
}

bool cKiemChungVien::getLoaiNV()
{
	return 1;
}