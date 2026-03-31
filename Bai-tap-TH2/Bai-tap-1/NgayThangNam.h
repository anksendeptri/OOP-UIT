#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H


class NgayThangNam
{
private:
    int iNgay, iThang, iNam;
public:
    //gán giá trị mặc định cho constructor
    NgayThangNam(int ngay = 1, int thang = 1, int nam = 1);
    void Nhap();
    void Xuat();
    void NgayThangNamTiepTheo();
};

#endif // NGAYTHANGNAM_H
