#include <iostream>
#include "cDaGiac.h"

using namespace std;

int main()
{
    cDaGiac A;
    A.Nhap();
    A.Xuat();
    cout << endl;

    //tinh chu vi, dien tich
    cout << "Chu vi da giac la: " << A.tinhChuVi();
    cout << endl;
    cout << "Dien tich da giac la: " << A.tinhDienTich();
    cout << endl;

    //tinh tien
    Diem vtor;
    cout << "Nhap vao toa do (x y) cua vector tinh tien: \n";
    cin >> vtor.x >> vtor.y;
    A.TinhTien(vtor);
    cout << "Sau khi tinh tien. ";
    A.Xuat();
    cout << endl;

    //quay da giac
    double a;
    cout << "Nhap vao goc quay alpha (radian): \n";
    cin >> a;
    A.Quay(a);
    cout << "Sau khi quay. ";
    A.Xuat();
    cout << endl;

    //phong to/thu nho
    double k;
    cout << "k > 1: phong to || k < 1: thu nho \n";
    cout << "Nhap vao he so k (k > 0): \n";
    cin >> k;
    A.ThuPhong(k);
    A.Xuat();
    return 0;
}
