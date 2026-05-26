#include "cNhanVien.h"

cNhanVien::cNhanVien()
{
	tuoi = 0;
	luongCoBan = 0;
}

void cNhanVien::nhap()
{
	cout << "Nhap ma nhan vien:\n";
	getline(cin, maNV);
	cout << "Nhap ho ten:\n";
	getline(cin, hoTen);
	cout << "Nhap tuoi:\n";
	cin >> tuoi;
	cin.ignore();
	cout << "Nhap so dien thoai:\n";
	getline(cin, sdt);
	cout << "Nhap email:\n";
	getline(cin, email);
	cout << "Nhap luong co ban:\n";
	cin >> luongCoBan;
}

void cNhanVien::xuat()
{
	cout << "|MaNV: " << maNV
		<< "|Ho ten: " << hoTen
		<< "|Tuoi: " << tuoi
		<< "|SDT: " << sdt
		<< "|email: " << email;
}

