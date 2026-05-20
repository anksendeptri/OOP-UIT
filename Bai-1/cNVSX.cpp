#include "cNVSX.h"
#include <iostream>
using namespace std;

cNVSX::cNVSX()
{
	iSoSanPham = 0;
	luongCanBan = 0;
}

bool cNVSX::getLoaiNV()
{
	return 0;
}

void cNVSX::nhap()
{
	cNhanVien::nhap();
	cout << "Nhap luong can ban: \n";
	cin >> luongCanBan;
	cout << "Nhap so san pham: \n";
	cin >> iSoSanPham;
	luong = luongCanBan + iSoSanPham * 5000;
}

long long cNVSX::getLuong()
{
	return luong;
}
