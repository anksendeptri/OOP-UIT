#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main()
{
    SoPhuc A, B;
    cout << "Nhap so phuc A: \n";
    A.Nhap();
    cout << "Nhap so phuc B: \n";
    B.Nhap();
    cout << "So phuc A la: ";
    A.Xuat();
    cout << endl;
    cout << "So phuc B la: ";
    B.Xuat();
    cout << endl;

    //tinh toan
    cout << "Tong = ";
    A.tinhTong(B).Xuat();
    cout << endl;
    cout << "Hieu = ";
    A.tinhHieu(B).Xuat();
    cout << endl;
    cout << "Tich = ";
    A.tinhTich(B).Xuat();
    cout << endl;
    cout << "Thuong = ";
    A.tinhThuong(B);
    cout << endl;
}
