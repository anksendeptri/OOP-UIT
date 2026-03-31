#include "NgayThangNam.h"
#include <iostream>

using namespace std;

//constructor
NgayThangNam::NgayThangNam(int ngay, int thang, int nam)
{
     iNgay = ngay;
     iThang = thang;
     iNam = nam;
}

//hàm kiểm tra năm nhuận
//input: năm | output: 0 hoặc 1
bool laNamNhuan(int nam)
{
    return ((nam % 400 == 0) || (nam % 4 == 0 && nam & 100 != 0));
}

//hàm trả về số ngày trong tháng
//input: tháng năm | output: số ngày trong tháng

int traSoNgay(int thang, int nam)
{
    switch (thang)
    {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return laNamNhuan(nam) ? 29 : 28;
        default: return 31;
    }
}

//hàm nhập
void NgayThangNam::Nhap()
{
    cout << "Nhap ngay thang nam: \n";
    //nhập đến khi đúng mới thôi
    while (!(cin >> iNgay >> iThang >> iNam) || iNam < 1 || iThang < 1 || iThang > 12 || iNgay < 1 || iNgay > traSoNgay(iThang, iNam))
    {
        cout << "Nhap lai! \n";
        // xóa lỗi nhập
        cin.clear();
        cin.ignore(100, '\n');
    }
}

//hàm xuất
void NgayThangNam::Xuat()
{
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}

//hàm ngày tiếp theo
//tăng ngày tháng năm hiện tại lên 1 ngày
void NgayThangNam::NgayThangNamTiepTheo()
{
    iNgay++;
    //nếu quá số ngày trong tháng thì sang tháng mới
    if (iNgay > traSoNgay(iThang, iNam))
    {
        iNgay = 1;
        iThang++;
    }
    //tháng vượt quá 12 thì sang năm mới
    if(iThang > 12)
    {
        iThang = 1;
        iNam++;
    }
}
