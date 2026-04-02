#ifndef GIOPHUTGIAY_H
#define GIOPHUTGIAY_H


class GioPhutGiay
{
private:
    int iGio, iPhut, iGiay;
public:
    GioPhutGiay(int gio = 0, int phut = 0, int gaiy = 0);
    void Nhap();
    void Xuat();
    GioPhutGiay TinhCongThemMotGiay();
};

#endif // GIOPHUTGIAY_H
