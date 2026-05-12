#include "CDate.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long long tienGui;
	double laiSuatNam;
	cout << "Nhap so tien gui (VND): ";
	cin >> tienGui;
	cout << "Nhap lai suat nam: ";
	cin >> laiSuatNam;
	CDate ngayGui, ngayNhan;
	cout << "Nhap ngay gui: \n";
	cin >> ngayGui;
	cout << "Nhap ngay nhan: \n";
	cin >> ngayNhan;
	long long soNgayGui = ngayNhan - ngayGui;
	cout << "So ngay gui tien la: " << soNgayGui << " ngay" << endl;
	double tienLai = tienGui * laiSuatNam * soNgayGui/ 365;
	cout << "Tien lai nhan duoc la: " << fixed << setprecision(2) << tienLai << " VND" << endl;
}
