#include "cNhanVienSX.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double cNhanVienSX::donGia = 0;
//ctr
cNhanVienSX::cNhanVienSX(string maNV, string hoTen, Date ngaySinh, int soSanPham)
{
	this->maNV = maNV;
	this->hoTen = hoTen;
	this->ngaySinh = ngaySinh;
	this->soSanPham = soSanPham;
}

//phuong thuc lay ten nhan vien
string cNhanVienSX::getTen()
{
	return hoTen;
}

//phuong thuc tinh tuoi nhan vien
//cach thuc: lay nam hien tai tru di nam sinh cua nhan vien
int cNhanVienSX::getTuoi()
{
	return 2026 - ngaySinh.year;
}

//phuong thuc nhap thong tin nhan vien
void cNhanVienSX::nhap()
{
	cout << "Nhap ma nhan vien: ";
	cin.ignore();
	getline(cin, maNV);
	cout << "Nhap ten nhan vien: ";
	getline(cin, hoTen);
	cout << "Nhap ngay sinh (ngay thang nam): ";
	cin >> ngaySinh.day >> ngaySinh.month >> ngaySinh.year;
	cout << "Nhap so san pham da gia cong: ";
	cin >> soSanPham;
}

//phuong thuc xuat thong tin nhan vien
void cNhanVienSX::xuat()
{
	cout << setprecision(0) << fixed;
	cout << maNV << "\t|" << hoTen << "\t|" << ngaySinh.day << "/" << ngaySinh.month << "/" << ngaySinh.year << "\t|" << soSanPham << "\t\t|" << tinhLuong() << endl;
}

//phuong thuc set don gia san pham
void cNhanVienSX::setDonGia(double dg)
{
	donGia = dg;
}

//phuong thuc tinh luong nhan vien
//cach thuc: luong = don gia * so san pham
double cNhanVienSX::tinhLuong()
{
	return donGia * soSanPham;
}
