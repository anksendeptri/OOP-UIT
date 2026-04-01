#include "PhanSo.h"
#include <iostream>
#include <numeric>

using namespace std;
//Constructor
PhanSo::PhanSo(int tu, int mau)
{
    iTu = tu;
    iMau = mau;
    RutGon();
}

//hàm rút gọn: rút gọn bằng cách chia cho ucln
void PhanSo::RutGon()
{
    //kiểm tra mẫu số, nếu = 0 thì thông báo
    //bước kiểm tra này để loại các trường hợp sai khi tạo ps bằng Constructor
    if (iMau == 0){
        cout << "Mau so khong duoc bang 0! \n";
        return;
    }
    //rút gọn
    int ucln = gcd(iTu, iMau);
    iTu /= ucln;
    iMau /= ucln;
    //sắp xếp dấu trừ
    if (iMau < 0) {
    iTu = -iTu;
    iMau = -iMau;
    }
}

//phương thức nhập
void PhanSo::Nhap()
{
    cout << "Nhap tu so va mau so: \n";
    //kiểm tra điều kiện nhập
    while(!(cin >> iTu >> iMau) || iMau == 0)
    {
        cout << "Loi! Khong duoc nhap ky tu va mau so khac 0! \nMoi nhap lai!\n";
        //xóa lỗi nhập
        cin.clear();
        //xóa ký tự sai
        cin.ignore(100, '\n');
    }
    //rút gọn sau khi nhập
    RutGon();
}

//phương thức xuất
//xuất số nguyên khi mẫu = 1
void PhanSo::Xuat() const
{
    if (iMau == 1) cout << iTu << endl;
    else cout << iTu << "/" << iMau << endl;
}

//phương thức tính tổng:
//input: 1 phân số khác để cộng với phân số this
//output: phân số tổng
PhanSo PhanSo::tinhTong(PhanSo psk) const
{
    //khởi tạo 1 phân số có giá trị là tổng của của 2 phân số
    return PhanSo(this->iTu*psk.iMau + psk.iTu*this->iMau, this->iMau*psk.iMau);
    //đã rút gọn trong Constructor
}

//phương thức tính hiệu:
//tương tự như tổng
PhanSo PhanSo::tinhHieu(PhanSo psk) const
{
    return PhanSo(this->iTu*psk.iMau - psk.iTu*this->iMau, this->iMau*psk.iMau);
}

//phương thức tính tích
//tương tự như tổng
PhanSo PhanSo::tinhTich(PhanSo psk) const
{
    return PhanSo(this->iTu*psk.iTu, this->iMau*psk.iMau);
}

//phương thức tính thương
//tương tự như tính tổng
PhanSo PhanSo::tinhThuong(PhanSo psk) const
{
    //kiểm tra trường hợp chia 0
    if(psk.iTu == 0)
    {
        cout << "Khong the chia cho phan so bang ";
        //trả về giá trị 0 để bổ sung cho câu trên
        return PhanSo(0, 1);
    }
    return PhanSo(this->iTu*psk.iMau, this->iMau*psk.iTu);
}

//phương thức so sánh:
//input: 1 phân số khác để so sánh với phân số this | output: không có
//xuất ra kết quả chứ không trả về giá trị
void PhanSo::SoSanh(PhanSo psk) const
{
    cout << this->iTu << "/" << this->iMau;
    if (this->iTu * psk.iMau > psk.iTu * this->iMau)
        cout << " > ";
    else if (this->iTu * psk.iMau < psk.iTu * this->iMau)
        cout <<" < ";
    else
        cout <<" = ";
    psk.Xuat();
}

