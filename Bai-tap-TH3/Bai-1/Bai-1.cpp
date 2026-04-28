#include <iostream>
#include "cTamGiac.h"

using namespace std;

int main()
{
    cTamGiac A;
    A.Nhap();
    A.Xuat();
    cout << endl;

    //kiem tra
	if (A.KiemTra() == 0)
        cout << "Day la tam giac thuong\n";
    else if (A.KiemTra() == 1)
        cout << "Day la tam giac vuong\n";
    else if (A.KiemTra() == 2)
        cout << "Day la tam giac can\n";
    else if (A.KiemTra() == 3)
        cout << "Day la tam giac vuong can\n";
    else
        cout << "Day la tam giac deu\n";

    //tinh chu vi, dien tich
    cout << "Chu vi tam giac la: " << A.tinhChuVi();
    cout << endl;
    cout << "Dien tich tam giac la: " << A.tinhDienTich();
    cout << endl;

    //tinh tien
    Diem vtor;
    cout << "Nhap vao toa do (x y) cua vector tinh tien: \n";
    cin >> vtor.x >> vtor.y;
    A.TinhTien(vtor);
    cout << "Sau khi tinh tien. ";
    A.Xuat();
    cout << endl;

    //quay tam giac
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
