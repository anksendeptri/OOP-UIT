#include "SoPhuc.h"
#include <iostream>

using namespace std;
//Constructor
SoPhuc::SoPhuc(int thuc, int ao)
{
    iThuc = thuc;
    iAo = ao;
}

//phuong thuc nhap
//yeu cau nguoi dung nhap den khi nhap dung
void SoPhuc::Nhap()
{
    cout << "Nhap phan thuc va phan ao: \n";
    while(!(cin >> iThuc >> iAo))
    {
        cout << "Nhap sai! Yeu cau nhap lai: \n";
        cin.clear();
        cin.ignore(100,'\n');
    }
}

//phuong thuc xuat
//xuat ra phan thuc va phan ao, co dieu chinh dau +-
void SoPhuc::Xuat() const
{
    cout << iThuc << ((iAo < 0) ? "" : "+") << iAo << "i";
}

//phuong thuc tinh tong
//input: 1 so phuc B | output: tong cua so phuc this va B
SoPhuc SoPhuc::tinhTong(const SoPhuc& B) const
{
    return SoPhuc(this->iThuc + B.iThuc, this->iAo + B.iAo);
}

//phuong thuc tinh hieu
//tuong tu nhu tinh tong
SoPhuc SoPhuc::tinhHieu(const SoPhuc& B) const
{
    return SoPhuc(this->iThuc - B.iThuc, this->iAo - B.iAo);
}

//phuong thuc tinh tich
//tuong tu nhu tinh tong

SoPhuc SoPhuc::tinhTich(const SoPhuc& B) const
{
    return SoPhuc(this->iThuc*B.iThuc - B.iAo*this->iAo, this->iAo*B.iThuc + B.iAo*this->iThuc);
}

//phuong thuc tinh thuong
//ket qua co the la so phuc thap phan nen can xu li rieng

void SoPhuc::tinhThuong(const SoPhuc& B) const
{
    float thuc, ao;
    thuc = (float)(this->iThuc*B.iThuc + B.iAo*this->iAo) / (B.iThuc*B.iThuc + B.iAo*B.iAo);
    ao = (float)(this->iAo*B.iThuc - B.iAo*this->iThuc) / (B.iThuc*B.iThuc + B.iAo*B.iAo);
    cout << thuc << ((ao < 0) ? "" : "+") << ao << "i";
}
