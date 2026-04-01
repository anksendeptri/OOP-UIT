#ifndef PHANSO_H
#define PHANSO_H


class PhanSo
{
private:
    int iTu, iMau;
public:
    PhanSo(int tu = 0, int mau = 1);
    void Nhap();
    void Xuat() const;
    void RutGon();
    PhanSo tinhTong(PhanSo psk) const;
    PhanSo tinhHieu(PhanSo psk) const;
    PhanSo tinhTich(PhanSo psk) const;
    PhanSo tinhThuong(PhanSo psk) const;
    void SoSanh(PhanSo psk) const;
};

#endif // PHANSO_H
