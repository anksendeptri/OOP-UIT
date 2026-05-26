#include "cSinhVien.h"

cSinhVien::cSinhVien()
{
	soTinChi = 0;
	diemTB = 0;
}

void cSinhVien::nhap()
{
	cout << "Nhap ma sinh vien:\n";
	getline(cin, maSV);
	cout << "Nhap ho ten:\n";
	getline(cin, hoTen);
	cout << "Nhap dia chi:\n";
	getline(cin, diaChi);
	cout << "Nhap so tin chi:\n";
	cin >> soTinChi;
	cout << "Nhap diem trung binh:\n";
	cin >> diemTB;
	cin.ignore();
}

void cSinhVien::xuat()
{
	cout << "|Ma sinh vien: " << maSV
		<< " |Ho ten: " << hoTen
		<< " |Dia chi: " << diaChi
		<< " |So tin chi: " << soTinChi
		<< " |Diem trung binh: " << diemTB;
}

double cSinhVien::getDiemTB()
{
	return diemTB;
}
