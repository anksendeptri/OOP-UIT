#include "cTamGiac.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//ctr
cTamGiac::cTamGiac()
{
    n = 3;
}

//Phuong thuc nhap
//Nhap vao so dinh va toa do cua tung dinh
void cTamGiac::Nhap()
{
    cout << "Nhap lan luot cac dinh theo chieu kim dong ho: \n";
    for (int i = 0; i < n; i++)
    {
        Diem temp;
        cout << "Nhap toa do (x y) dinh " << i + 1 << endl;
        cin >> temp.x >> temp.y;
        Dinh.push_back(temp);
    }
}

//Phuong thuc xuat
void cTamGiac::Xuat()
{
    cout << "Toa do cac dinh lan luot la: \n";
    for (auto w : Dinh)
    {
        cout << "(" << w.x << ", " << w.y << ")" << " ";
    }
}

//Phuong thuc kiem tra 
//Tra ve so tu 0 den 4 tuong ung voi loai tam giac
//0: tam giac thuong
//1: tam giac vuong 
//2: tam giac can
//3: tam giac vuong can
//4: tam giac deu
int cTamGiac::KiemTra()
{
    double a = sqrt(pow(Dinh[1].x - Dinh[0].x, 2) + pow(Dinh[1].y - Dinh[0].y, 2));
    double b = sqrt(pow(Dinh[2].x - Dinh[1].x, 2) + pow(Dinh[2].y - Dinh[1].y, 2));
    double c = sqrt(pow(Dinh[0].x - Dinh[2].x, 2) + pow(Dinh[0].y - Dinh[2].y, 2));
    bool deu = a == b && b == c;
    bool can = a == b || b == c || a == c;
    bool vuong = a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b;
    bool vcan = can && vuong;
    if (deu)
        return 4; //tam giac deu
    else if(vcan)
		return 3; //tam giac vuong can
    else if (can)
        return 2; //tam giac can
    else if (vuong)
        return 1; //tam giac vuong
    else
        return 0; //tam giac thuong
}

//Phuong thuc tinh chu vi
//tra ve chu vi cua tam giac
double cTamGiac::tinhChuVi()
{
    double cv = 0;
    for (int i = 0; i < n; i++)
    {
        double dx = Dinh[i].x - Dinh[(i + 1) % n].x;
        double dy = Dinh[i].y - Dinh[(i + 1) % n].y;
        cv += sqrt(dx * dx + dy * dy);
    }
    return cv;
}
double cTamGiac::tinhDienTich()
{
    double dt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        dt += Dinh[i].x * Dinh[j].y - Dinh[j].x * Dinh[i].y;
    }
    return abs(dt) / 2.0;
}
//phuong thuc tinh tien
//input: vector tinh tien
//cac diem tren tam giac duoc tinh tien theo vector
void cTamGiac::TinhTien(Diem vtor)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].x += vtor.x;
        Dinh[i].y += vtor.y;
    }
}

//phuong thuc quay
//input: goc alpha (a)
//quay toa do cac dinh quanh trong tam G 1 goc alpha
void cTamGiac::Quay(double a)
{
    //tinh trong tam
    Diem G;
    G.x = 0;
    G.y = 0;
    for (int i = 0; i < n; i++)
    {
        G.x += Dinh[i].x;
        G.y += Dinh[i].y;
    }
    G.x /= n;
    G.y /= n;

    //quay
    for (int i = 0; i < n; i++)
    {
        double x = Dinh[i].x;
        double y = Dinh[i].y;
        Dinh[i].x = G.x + (x - G.x) * cos(a) - (y - G.y) * sin(a);
        Dinh[i].y = G.y + (x - G.x) * sin(a) + (y - G.y) * cos(a);
    }
}

//phuong thuc phong to/thu nho
//input: he so k (k > 1: phong to || k < 1: thu nho)
//phong to (thu nho) tam giac len k lan
void cTamGiac::ThuPhong(double k)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].x = Dinh[i].x * k;
        Dinh[i].y = Dinh[i].y * k;
    }
}
