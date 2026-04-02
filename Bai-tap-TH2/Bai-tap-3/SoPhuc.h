#ifndef SOPHUC_H
#define SOPHUC_H


class SoPhuc
{
private:
    int iThuc, iAo;
public:
    SoPhuc(int thuc = 0, int ao = 0);
    void Nhap();
    void Xuat() const;
    SoPhuc tinhTong(const SoPhuc& B) const;
    SoPhuc tinhHieu(const SoPhuc& B) const;
    SoPhuc tinhTich(const SoPhuc& B) const;
    //thuong cua 2 so phuc co the la so phuc thap phan
    void tinhThuong(const SoPhuc& B) const;
};

#endif // SOPHUC_H
