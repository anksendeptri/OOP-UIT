#include "cNVVP.h"
#include <iostream>
using namespace std;

cNVVP::cNVVP()
{
	iSoNgayLamViec = 0;
}

bool cNVVP::getLoaiNV()
{
	return 1;
}

void cNVVP::nhap()
{
	cNhanVien::nhap();
	cout << "Nhap so ngay lam viec: \n";
	cin >> iSoNgayLamViec;
	luong = iSoNgayLamViec * 100000;
}

long long cNVVP::getLuong()
{
	return luong;
}
