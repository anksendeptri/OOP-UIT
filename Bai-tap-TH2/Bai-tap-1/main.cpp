#include <iostream>
#include "NgayThangNam.h"

using namespace std;

int main()
{
    NgayThangNam day;
    day.Nhap();
    day.NgayThangNamTiepTheo();
    cout << "Ngay thang nam tiep theo la: \n";
    day.Xuat();
    return 0;
}
