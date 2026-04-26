#ifndef CTAMGIAC_H
#define CTAMGIAC_H
#include <vector>
struct Diem
{
    double x, y;
};

class cTamGiac
{
public:
    cTamGiac();
    void Nhap();
    void Xuat();
    int KiemTra();
    double tinhChuVi();
    double tinhDienTich();
    void TinhTien(Diem v);
    void Quay(double a);
    void ThuPhong(double k);
private:
    int n;
    std::vector<Diem> Dinh;
};

#endif // CTAMGIAC_H
