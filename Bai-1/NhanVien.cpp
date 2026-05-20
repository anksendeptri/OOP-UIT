#include "cNhanVien.h"
#include "cNVSX.h"
#include "cNVVP.h"
#include "cCongTy.h"
#include <iostream>

using namespace std;

int main()
{
    cCongTy A;
    A.nhapDanhSach();
    A.xuatDanhSach();
    cout << "Tong luong cong ty phai tra la: " << A.tongLuong() << "(VND)" << endl;
    cout << "Nhan vien san xuat co luong thap nhat: ";
    A.getMinLuong()->xuat();
    cout << endl;
    cout << "Nhan vien van phong co tuoi cao nhat: ";
    A.getMaxTuoi()->xuat();
    return 0;
}
