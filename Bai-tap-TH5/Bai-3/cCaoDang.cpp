#include "cCaoDang.h"

cCaoDang::cCaoDang()
{
	diemTN = 0;
}

void cCaoDang::nhap()
{
	cSinhVien::nhap();
	cout << "Nhap diem tot nghiep:\n";
	cin >> diemTN;
	cin.ignore();
}

bool cCaoDang::getLoaiSV()
{
	return 0;
}

bool cCaoDang::totNghiep()
{
	if (soTinChi >= 120 && diemTB >= 5 && diemTN >= 5)
		return 1;
		return 0;
}