#include <iostream>
#include "GioPhutGiay.h"

using namespace std;

int main()
{
    GioPhutGiay tg;
    tg.Nhap();
    cout << "Thoi gian hien tai la: ";
    tg.Xuat();
    cout << endl;
    cout << "Thoi gian 1 giay sau la: ";
    tg.TinhCongThemMotGiay();
    tg.Xuat();
    return 0;
}
