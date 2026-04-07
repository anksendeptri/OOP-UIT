#include "GioPhutGiay.h"
#include <iostream>

using namespace std;

//Constructor
//gan gia tri truyen vao cho iGio, iPhut, iGiay hoac gan gia tri mac dinh = 0
GioPhutGiay::GioPhutGiay(int gio, int phut, int giay)
{
    if (gio >= 0 && gio <= 24 && phut >= 0 && phut <= 60 && giay >= 0 && giay <= 60)
    {
        iGio = gio;
        iPhut = phut;
        iGiay = giay;
    }
    else
    {
        cout << "Thoi gian khong xac dinh! \n";
        iGio = 0;
        iPhut = 0;
        iGiay = 0;
    }
}

//phuong thuc nhap
//yeu cap nhap cho den khi nhap dung
void GioPhutGiay::Nhap()
{
    cout << "Nhap vao gio phut giay: \n";
    while(!(cin >> iGio >> iPhut >> iGiay) || !(iGio >= 0 && iGio <= 24 && iPhut >= 0 && iPhut <= 60 && iGiay >= 0 && iGiay <= 60))
    {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "nhap lai! \n";
    }
}

//phuong thuc xuat
//xuat giong nhu dong ho dien tu
void GioPhutGiay::Xuat()
{
    if (iGio == 24) iGio = 0; //24h = 0h
    if (iPhut == 60) iPhut = 0;
    if (iGiay == 60) iGiay = 0;
    cout << iGio << ":";
    cout << ((iPhut < 10) ? "0" : "");
    cout << iPhut << ":";
    cout << ((iGiay < 10) ? "0" : "");
    cout << iGiay;
}

//phuong thuc cong them 1 giay
//tra ve thoi gian o giay tiep theo
GioPhutGiay GioPhutGiay::TinhCongThemMotGiay()
{
    iGiay++;
    if (iGiay > 59)
    {
        iGiay = 0;
        iPhut++;
    }
    if (iPhut > 59)
    {
        iPhut = 0;
        iGio++;
    }
    if (iGio > 23)
        iGio = 0;
    return *this;
}
