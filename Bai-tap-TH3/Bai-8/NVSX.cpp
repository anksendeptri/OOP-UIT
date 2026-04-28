#include "cNhanVienSX.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	//tao danh sach nhan vien
	vector<cNhanVienSX> danhSach;
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	danhSach.resize(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
		danhSach[i].nhap();
		cout << endl;
	}
	double dg;
	cout << "Nhap don gia san pham: ";
	cin >> dg;
	cNhanVienSX::setDonGia(dg);

	//nhan vien co luong thap nhat
	double minLuong = danhSach[0].tinhLuong();
	int indexMin = 0;
	for (int i = 1; i < n; i++)
	{
		if (danhSach[i].tinhLuong() < minLuong)
		{
			minLuong = danhSach[i].tinhLuong();
			indexMin = i;
		}
	}
	cout << setprecision(0) << fixed;
	cout << "Nhan vien co luong thap nhat la: " << danhSach[indexMin].getTen() << " - Luong: " << minLuong << endl;

	//tinh tong luong cong ty phai tra
		double tong = 0;
		for (int i = 0; i < n; i++)
		{
			tong += danhSach[i].tinhLuong();
		}
		cout << "Tong luong cong ty phai tra: " << tong << endl;

	//nhan vien co tuoi cao nhat
	int maxTuoi = danhSach[0].getTuoi();
	int indexMax = 0;
	for (int i = 1; i < n; i++)
	{
		if (danhSach[i].getTuoi() > maxTuoi)
		{
			maxTuoi = danhSach[i].getTuoi();
			indexMax = i;
		}
	}
	cout << "Nhan vien co tuoi cao nhat la: " << danhSach[indexMax].getTen() << " - Tuoi: " << maxTuoi << endl;

	//sap xep danh sach nhan vien theo luong tang dan
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (danhSach[j].tinhLuong() > danhSach[j + 1].tinhLuong())
				swap(danhSach[j], danhSach[j + 1]);
		}
	}
	//danh sach sau khi sap xep
	cout << "Danh sach nhan vien sap xep theo luong:" << endl;
	cout << "Ma NV\t|Ho Ten\t\t|Ngay Sinh\t|So San Pham\t|Luong" << endl;
	for (int i = 0; i < n; i++)
	{
		danhSach[i].xuat();
	}

	return 0;
}