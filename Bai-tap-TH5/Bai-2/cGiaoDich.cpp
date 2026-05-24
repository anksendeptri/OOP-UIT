#include "cGiaoDich.h"

cGiaoDich::cGiaoDich()
{
	maGD = "";
	donGia = 0;
	dienTich = 0;
}

void cGiaoDich::nhap()
{
	cout << "Nhap ma giao dich:\n";
	cin.ignore();
	getline(cin, maGD);
	cout << "Nhap ngay giao dich (ngay thang nam):\n";
	cin >> ngayGD.ngay >> ngayGD.thang >> ngayGD.nam;
	cout << "Nhap don gia:\n";
	cin >> donGia;
	cout << "Nhap dien tich:\n";
	cin >> dienTich;
}

void cGiaoDich::xuat()
{
	cout << "| " << setw(20) << maGD << "| " << setw(12) << ngayGD.ngay << "/" << ngayGD.thang << "/" << ngayGD.nam
	   	 << "| " << setw(20) << donGia << "| " << setw(20) << dienTich << "| " << setw(20) << this->thanhTien() << "|";
}

date cGiaoDich::getNgayGD()
{
	return ngayGD;	
}