#ifndef CDAGIAC_H
#define CDAGIAC_H
#include <vector>
struct Diem
{
    double x, y;
};

class cDaGiac
{
public:
    cDaGiac();
    void Nhap();
    void Xuat();
    double tinhChuVi();
    double tinhDienTich();
    void TinhTien(Diem v);
    void Quay(double a);
    void ThuPhong(double k);
private:
    int n;
    std::vector<Diem> Dinh;
};

#endif // CDAGIAC_H
