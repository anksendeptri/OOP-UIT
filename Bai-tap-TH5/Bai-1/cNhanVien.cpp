#include "cNhanVien.h"
#include <iostream>
using namespace std;

cNhanVien::cNhanVien()
{
	sHoTen = "";
	sNgaySinh.day = 0;
	sNgaySinh.month = 0;
	sNgaySinh.year = 0;
	luong = 0;
}

void cNhanVien::nhap()
{
	cout << "Nhap ho ten nhan vien: \n";
	getline(cin, sHoTen);
	cout << "Nhap ngay sinh nhan vien (day month year): \n";
	cin >> sNgaySinh.day >> sNgaySinh.month >> sNgaySinh.year;
}

void cNhanVien::xuat()
{
	cout << sHoTen << "\t\t | " << sNgaySinh.day << "/" << sNgaySinh.month << "/" << sNgaySinh.year << "\t | " << luong << "(VND)";
}

//cach thuc: tinh trong so ngay sinh theo cong thuc ben duoi, ai co trong so lon hon thi tuoi nho hon
long long cNhanVien::tinhTrongSoNgaySinh()
{
	return (sNgaySinh.year * 10000 + sNgaySinh.month * 100 + sNgaySinh.day);
}