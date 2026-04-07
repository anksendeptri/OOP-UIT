#include "PhanSo.h"
#include <iostream>

using namespace std;

int main()
{
//tạo 2 phân số
PhanSo A, B;
cout << "Nhap phan so A: \n";
A.Nhap();
cout << "Nhap phan so B: \n";
B.Nhap();
//đã tự động rút gọn trong phương thức nhập rồi
cout << "Phan so A la: ";
A.Xuat();
cout << endl;
cout << "Phan so B la: ";
B.Xuat();
cout << endl;

//tính toán
cout << "Tong: ";
A.tinhTong(B).Xuat();
cout << endl;
cout << "Hieu: ";
A.tinhHieu(B).Xuat();
cout << endl;
cout << "Tich: ";
A.tinhTich(B).Xuat();
cout << endl;
cout << "Thuong: ";
A.tinhThuong(B).Xuat();
cout << endl;
cout << "So sanh: ";
A.SoSanh(B);
return 0;
}


