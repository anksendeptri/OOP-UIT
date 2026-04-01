/*Bài tập 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả. 
Bài tập 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả. 
Bài tập 3: Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa 
chúng và xuất kết quả.*/
#include <iostream>
#include <numeric>
using namespace std;

class phanSo
{
private:
    long long Tu, Mau;
    void rutGon()
    {
        //kiem tra mau so, neu = 0 thi thong bao
        if (Mau == 0){
            cout << "Mau so khong duoc bang 0! \n";
            return;
        }
        // rut gon phan so
        long long ucln = gcd(Tu, Mau);
        Tu /= ucln;
        Mau /= ucln;

        // sap xep dau tru
        if (Mau < 0) {
        Tu = -Tu;
        Mau = -Mau;
        }
    }

public:
    //ham khoi tao
    phanSo(long long tu = 0, long long mau = 1)
    {
        Tu = tu;
        Mau = mau;
        rutGon();
    }
    //ham nhap phan so
    void Nhap()
    {
        cout << "Nhap tu so va mau so: \n";
        //kiem tra dieu kien nhap, neu nhap sai thi nhap lai
        while(!(cin >> Tu >> Mau) || Mau == 0)
        {
            cout << "Loi! Khong duoc nhap ky tu va mau so khac 0! \nMoi nhap lai!\n";
            //xoa loi nhap sai
            cin.clear();
            //xoa ky tu sai trong bo nho
            cin.ignore(100, '\n');
        }

        //rut gon sau khi nhap
        rutGon();
    }

    //ham so sanh phan so nay voi phan so khac
    phanSo soSanh(phanSo psk)
    {
        //tra ve phan so lon hon
        if (this->Tu * psk.Mau > psk.Tu * this->Mau)
            return *this;
        else return psk;
    }

    //ham xuat phan so
    void Xuat()
    {
        //neu mau = 1 th� xuat so nguyen luon cho dep
        if (Mau == 1) cout << Tu << endl;
        else cout << Tu << "/" << Mau << endl;
    }
    //ham tong 2 phan so
    phanSo Tong(phanSo psk)
    {
        //khoi tao phan so tra ve
        return phanSo(this->Tu*psk.Mau + psk.Tu*this->Mau, this->Mau*psk.Mau);
        //da rut gon trong ham khoi tao roi
    }
    phanSo Hieu(phanSo psk)
    {
        //tuong tu ham tong
        return phanSo(this->Tu*psk.Mau - psk.Tu*this->Mau, this->Mau*psk.Mau);
    }
    phanSo Tich(phanSo psk)
    {
        //tuong tu ham tong
        return phanSo(this->Tu*psk.Tu, this->Mau*psk.Mau);
    }
    phanSo Thuong(phanSo psk)
    {
        //loai bo truong hop chia cho 0
        if(psk.Tu == 0)
        {
            cout << "Khong the chia cho phan so bang ";
            return phanSo(0, 1);
        }
        //tuong tu ham tong
        return phanSo(this->Tu*psk.Mau, this->Mau*psk.Tu);
    }
};

int main()
{
    //tao 2 phan so
    phanSo ps1, ps2;
    cout << "Nhap phan so thu 1: \n";
    ps1.Nhap();
    cout << "Nhap phan so thu 2: \n";
    ps2.Nhap();
    cout << "Phan so lon nhat la: ";
    //xuat phan so duoc tra ve
    ps1.soSanh(ps2).Xuat();
    cout << "Tong 2 phan so la: ";
    ps1.Tong(ps2).Xuat();
    cout << "Hieu 2 phan so la: ";
    ps1.Hieu(ps2).Xuat();
    cout << "Tich 2 phan so la: ";
    ps1.Tich(ps2).Xuat();
    cout << "Thuong cua 2 phan so la: ";
    ps1.Thuong(ps2).Xuat();
    return 0;
}
