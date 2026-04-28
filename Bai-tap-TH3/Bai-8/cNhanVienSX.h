#pragma once
#include <vector>
#include <string>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};


class cNhanVienSX
{
private:
	string maNV;
	string hoTen;
	Date ngaySinh;
	int soSanPham;
	static double donGia;
public:
	cNhanVienSX(string maNV = "", string hoTen = "", Date ngaySinh = {0, 0, 0}, int soSanPham = 0);
	string getTen();
	int getTuoi();
	void nhap();
	void xuat();
	static void setDonGia(double dg = 0);
	double tinhLuong();	
	double tongLuong(vector<cNhanVienSX> danhSach, int n);
};

