#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H


class NgayThangNam
{
private:
    int iNgay, iThang, iNam;
public:
    //gán giá trị mặc định cho constructor
    NgayThangNam(int iNgay = 1, int iThang = 1, int iNam = 1);
    void Nhap();
    void Xuat();
    void NgayThangNamTiepTheo();
};

#endif // NGAYTHANGNAM_H
