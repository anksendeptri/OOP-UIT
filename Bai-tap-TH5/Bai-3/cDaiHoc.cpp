#include "cDaiHoc.h"

cDaiHoc::cDaiHoc()
{
	diemLuanVan = 0;
}

void cDaiHoc::nhap()
{
	cSinhVien::nhap();
	cout << "Nhap ten luan van:\n";
	getline(cin, tenLuanVan);
	cout << "Nhap diem luan van:\n";
	cin >> diemLuanVan;
}

bool cDaiHoc::getLoaiSV()
{
	return 1;
}

bool cDaiHoc::totNghiep()
{
	if (soTinChi >= 170 && diemLuanVan >= 5 && diemTB >= 5)
		return 1;
	return 0;
}