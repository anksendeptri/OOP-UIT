#include "cDat.h"
#include "cNhaPho.h"
#include "cCanHo.h"
#include <vector>

int main()
{
    vector<cGiaoDich*> VAKALAND;

    //Nhap danh sach
    bool flag = 1;
    do
    {
        cGiaoDich* gd = nullptr;
        int loai;
        cout << "Chon loai giao dich (GD dat: 1 |GD nha pho: 2 |GD can ho chung cu: 3)\n";
        cin >> loai;
        if (loai == 1)
            gd = new cDat;
        else if (loai == 2)
            gd = new cNhaPho;
        else
            gd = new cCanHo;
        gd->nhap();
        VAKALAND.push_back(gd);
        cout << "Ban muon them giao dich? (khong: 0| co: 1):\n";
        cin >> flag;
    } while (flag == 1);
    
    //tong so luong cho tung loai va tinh trung binh thanh tien cua gd can ho
    int dat = 0, nhaPho = 0, canHo = 0;
    long long tb = 0;
    for (auto gd : VAKALAND)
    {
        if (gd->getLoai() == 1)
            dat++;
        else if (gd->getLoai() == 2)
            nhaPho++;
        else
        {
            tb += gd->thanhTien();
            canHo++;
        }
    }
    tb /= (canHo == 0 ? 1 : canHo);
    cout << "Dat: " << dat << " giao dich\n";
    cout << "Nha pho: " << nhaPho << " giao dich\n";
    cout << "Can ho chung cu: " << canHo << " giao dich\n";
    cout << "Trung binh thanh tien cua giao dich can ho chung cu: " << tb << "(VND)\n";

    //gd nha pho co gia tri cao nhat
    cGiaoDich* max = nullptr;
    for (auto gd : VAKALAND)
    {
        if (gd->getLoai() == 2)
        {
            if (max == nullptr || max->thanhTien() < gd->thanhTien())
                max = gd;
        }
    }
    
    if (max != nullptr)
    {
        cout << "Giao dich nha pho co gia tri cao nhat:\n";
        cout << "| " << setw(20) << "Ma giao dich"
             << "| " << setw(20) << "Ngay giao dich"
             << "| " << setw(20) << "Don gia"
             << "| " << setw(20) << "Dien tich"
             << "| " << setw(20) << "Thanh tien" << "|\n";
        max->xuat();
        cout << endl;
    }
    else
        cout << "Khong co giao dich nha pho trong danh sach!\n";

    //danh sach cac giao dich cua thang 12 nam 2024
    cout << "Danh sach giao dich cua thang 12 nam 2024\n";
    cout << "| " << setw(20) << "Ma giao dich" 
         << "| " << setw(20) << "Ngay giao dich"
         << "| " << setw(20) << "Don gia" 
         << "| " << setw(20) << "Dien tich"
         << "| " << setw(20) << "Thanh tien" << "|\n";
    for (auto gd : VAKALAND)
    {
        date temp = gd->getNgayGD();
        if (temp.thang == 12 && temp.nam == 2024)
        {
            gd->xuat();
            cout << "\n";
        }
    }

    for (auto gd : VAKALAND)
    {
        delete gd;
    }
    VAKALAND.clear();
    return 0;
}