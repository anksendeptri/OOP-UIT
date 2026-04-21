#include "cDaGiac.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
//ctr
cDaGiac::cDaGiac()
{
    n = 0;
}

//Phuong thuc nhap
//Nhap vao so dinh va toa do cua tung dinh
void cDaGiac::Nhap()
{
    do
    {
        cout << "Nhap so dinh: \n";
        cin >> n;
    }while(n < 3);
    cout << "Nhap lan luot cac dinh theo chieu kim dong ho: \n";
    for (int i=0; i < n; i++)
    {
        Diem temp;
        cout << "Nhap toa do (x y) dinh " << i+1 << endl;
        cin >> temp.x >> temp.y;
        Dinh.push_back(temp);
    }
}

//Phuong thuc xuat
void cDaGiac::Xuat()
{
    cout << "Toa do cac dinh lan luot la: \n";
    for (auto w : Dinh)
    {
        cout << "(" << w.x << ", " << w.y << ")" << " ";
    }
}

//Phương thuc tinh chu vi
//tra ve chu vi cua da giac
double cDaGiac::tinhChuVi()
{
    double cv = 0;
    for (int i=0; i < n; i++)
    {
        double dx = Dinh[i].x - Dinh[(i + 1) % n].x;
        double dy = Dinh[i].y - Dinh[(i + 1) % n].y;
        cv += sqrt(dx * dx + dy * dy);
    }
    return cv;
}
double cDaGiac::tinhDienTich()
{
    double dt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = (i+1)%n;
        dt += Dinh[i].x*Dinh[j].y - Dinh[j].x*Dinh[i].y;
    }
    return abs(dt)/2.0;
}
//phuong thuc tinh tien
//input: vector tinh tien
//cac diem tren da giac duoc tinh tien theo vector
void cDaGiac::TinhTien(Diem vtor)
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
void cDaGiac::Quay(double a)
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
        Dinh[i].x = G.x + (x - G.x)*cos(a) - (y - G.y)*sin(a);
        Dinh[i].y = G.y + (x - G.x)*sin(a) + (y - G.y)*cos(a);
    }
}

//phuong thuc phong to/thu nho
//input: he so k (k > 1: phong to || k < 1: thu nho)
//phong to (thu nho) da giac len k lan
void cDaGiac::ThuPhong(double k)
{
    for (int i = 0; i < n; i++)
    {
        Dinh[i].x = Dinh[i].x * k;
        Dinh[i].y = Dinh[i].y * k;
    }
}
