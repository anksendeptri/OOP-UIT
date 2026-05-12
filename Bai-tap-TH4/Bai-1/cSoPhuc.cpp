#include "cSoPhuc.h"
#include <iostream>
#include <cmath>

using namespace std;
//Constructor
cSoPhuc::cSoPhuc(double thuc, double ao)
{
    dThuc = thuc;
    dAo = ao;
}

//operator nhap
//cach thuc: yeu cau nguoi dung nhap den khi nhap dung
istream& operator >>(istream& is, cSoPhuc& sp)
{
    cout << "Nhap phan thuc va phan ao: \n";
    while(!(is >> sp.dThuc >> sp.dAo))
    {
        cout << "Nhap sai! Yeu cau nhap lai: \n";
        is.clear();
        is.ignore(100,'\n');
    }
    return is;
}

//operator xuat
//cach thuc: xuat so thuc neu phan ao = 0, xuat phan ao neu phan thuc = 0, xuat ca 2 neu ca 2 khac 0
ostream& operator <<(ostream& os, const cSoPhuc& sp)
{
    if (sp.dAo == 0)
        os << sp.dThuc;
    else if (sp.dThuc == 0 && sp.dAo != 0)
    {
        if (sp.dAo == 1)
            os << "i";
        else if (sp.dAo == -1)
            os << "-i";
        else
            os << sp.dAo << "i";
    }
    else
    {
        os << sp.dThuc << (sp.dAo > 0 ? "+" : "");
        if (sp.dAo == 1)
            os << "i";
        else if (sp.dAo == -1)
            os << "-i";
        else
			os << sp.dAo << "i";
    }
    return os;
}

//operator cong
//input: 1 so phuc B | output: tong cua so phuc this va B
//cach thuc: cong phan thuc voi phan thuc, cong phan ao voi phan ao
cSoPhuc cSoPhuc::operator +(const cSoPhuc& B) const
{
    return cSoPhuc(this->dThuc + B.dThuc, this->dAo + B.dAo);
}

//operator tru
//input: 1 so phuc B | output: hieu cua so phuc this va B
//cach thuc: tru phan thuc voi phan thuc, tru phan ao voi phan ao
cSoPhuc cSoPhuc::operator -(const cSoPhuc& B) const
{
    return cSoPhuc(this->dThuc - B.dThuc, this->dAo - B.dAo);
}

//operator nhan
//input: 1 so phuc B | output: tich cua so phuc this va B
//cach thuc: nhan theo cong thuc (a+bi)(c+di) = (ac-bd) + (ad+bc)i
cSoPhuc cSoPhuc::operator *(const cSoPhuc& B) const
{
    return cSoPhuc(this->dThuc*B.dThuc - B.dAo*this->dAo, this->dAo*B.dThuc + B.dAo*this->dThuc);
}

//operator chia
//input: 1 so phuc B | output: thuong cua so phuc this va B
//cach thuc: chia theo cong thuc (a+bi)/(c+di) = ((ac+bd) + (bc-ad)i) / (c^2+d^2)
cSoPhuc cSoPhuc::operator /(const cSoPhuc& B) const
{
    if (B.dThuc == 0 && B.dAo == 0)
    {
        cout << "khong the chia cho 0!";
        return cSoPhuc();
    }
    double thuc, ao;
    thuc = (this->dThuc*B.dThuc + B.dAo*this->dAo) / (B.dThuc*B.dThuc + B.dAo*B.dAo);
    ao = (this->dAo*B.dThuc - B.dAo*this->dThuc) / (B.dThuc*B.dThuc + B.dAo*B.dAo);
    return cSoPhuc(thuc, ao);
}

//operator so sanh bang
//input: 1 so phuc B | output: true neu this va B bang nhau, false neu khac nhau
//cach thuc: so sanh phan thuc voi phan thuc, so sanh phan ao voi phan ao sao cho hieu giua chung nho hon sai so epsilon
bool cSoPhuc::operator ==(const cSoPhuc& B) const
{
    return (abs(this->dThuc - B.dThuc) < 1e-9) && (abs(this->dAo - B.dAo) < 1e-9);
}

//operator so sanh khac
//input: 1 so phuc B | output: true neu this va B khac nhau, false neu bang nhau
//cach thuc: so sanh phan thuc voi phan thuc, so sanh phan ao voi phan ao
bool cSoPhuc::operator !=(const cSoPhuc& B) const
{
    return !(*this == B);
}