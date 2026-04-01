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
cout << "Phan so A la: \n";
A.Xuat();
cout << "Phan so B la: \n";
B.Xuat();

//tính toán
cout << "Tong: \n";
A.tinhTong(B).Xuat();
cout << "Hieu: \n";
A.tinhHieu(B).Xuat();
cout << "Tich: \n";
A.tinhTich(B).Xuat();
cout << "Thuong: \n";
A.tinhThuong(B).Xuat();
cout << "So sanh: \n";
A.SoSanh(B);
return 0;
}
