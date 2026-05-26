#include "cKiemChungVien.h"
#include "cIT.h"
#include <vector>
int main()
{
    vector<cNhanVien*> HoanCau;
    //nhap danh sach
    bool flag = 0;
    do
    {
        cNhanVien* nv;
        bool loai;
        cout << "Chon loai nhan vien (IT: 0, Kiem chung vien: 1):\n";
        cin >> loai;
        cin.ignore();
        if (loai)
            nv = new cKiemChungVien;
        else
            nv = new cIT;
        nv->nhap();
        HoanCau.push_back(nv);
        cout << "Ban muon them nhan vien (co: 1, khong: 0):\n";
        cin >> flag;
    } while (flag);

    long long tb = 0;
    //xuat danh sach nv + tinh luong tb
    cout << "Danh sach nhan vien:\n";
    for (auto nv : HoanCau)
    {
        nv->xuat();
        cout << endl;
        tb += nv->tinhLuong();
    }

    cNhanVien* ITmax = nullptr;
    cNhanVien* KCmin = nullptr;
    cNhanVien* minLuong = nullptr;
    cNhanVien* maxLuong = nullptr;
    tb /= HoanCau.size();
    cout << "Danh sach nhan vien co luong thap hon luong trung binh:\n";
    for (auto nv : HoanCau)
    {
        // xuat danh sach nhan vien co luong thap hon luong tb
        if (nv->tinhLuong() < tb)
            nv->xuat();
        cout << endl;

        //tim nhan vien co luong cao nhat va thap nhat
        if (minLuong == nullptr || minLuong->tinhLuong() > nv->tinhLuong())
            minLuong = nv;
        if (maxLuong == nullptr || maxLuong->tinhLuong() < nv->tinhLuong())
            maxLuong = nv;
        //tim nhan vien IT luong cao nhat va kiem chung vien luong thap nhat
        if (nv->getLoaiNV())
        {
            if (KCmin == nullptr || KCmin->tinhLuong() > nv->tinhLuong())
                KCmin = nv;
        }
        else
        {
            if (ITmax == nullptr || ITmax->tinhLuong() < nv->tinhLuong())
                ITmax = nv;
        }
    }
    cout << "Nhan vien co luong cao nhat la:\n";
    maxLuong->xuat();
    cout << "\nNhap vien co luong thap nhat la:\n";
    minLuong->xuat();
    cout << "\nLap trinh vien co luong cao nhat la:\n";
    ITmax->xuat();
    cout << "\nKiem chung vien co luong thap nhat la: \n";
    KCmin->xuat();

    for (auto nv : HoanCau)
    {
        delete nv;
    }
    HoanCau.clear();
    
    return 0;

}
