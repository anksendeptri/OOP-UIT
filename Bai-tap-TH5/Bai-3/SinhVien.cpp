#include "cCaoDang.h"
#include "cDaiHoc.h"
#include <vector>
void xuatDS(vector<cSinhVien*> ds)
{
	for (int i = 0; i < ds.size(); i++)
	{
		ds[i]->xuat();
		cout << endl;
	}
}

int main()
{
	vector<cSinhVien*> danhSach;
	//nhap danh sach
	bool flag = 0;
	do
	{
		cSinhVien* sv;
		bool loai;
		cout << "Chon loai sinh vien (cao dang: 0, dai hoc: 1):\n";
		cin >> loai;
		cin.ignore();
		if (loai)
			sv = new cDaiHoc;
		else
			sv = new cCaoDang;
		sv->nhap();
		danhSach.push_back(sv);
		cout << "Ban muon them sinh vien? (co: 1, khong: 0)";
		cin >> flag;
	} while (flag);

	//xuat danh sach sinh vien du dieu kien tot nghiep va khong du dieu kien 
	//dem so luong sv kh du dieu kien cua moi loai
	vector<cSinhVien*> duDK;
	vector<cSinhVien*> kDuDK;
	int cdK = 0, dhK = 0;
	for (auto sv : danhSach)
	{
		if (sv->totNghiep())
			duDK.push_back(sv);
		else
		{
			kDuDK.push_back(sv);
			if (sv->getLoaiSV())
				dhK++;
			else
				cdK++;
		}
	}

	cout << "Danh sach sinh vien du dieu kien tot nghiep:\n";
	cout << "----------------------------------------------------------------\n";
	xuatDS(duDK);
	cout << "Danh sach sinh vien khong du dieu kien tot nghiep:\n";
	cout << "----------------------------------------------------------------\n";
	xuatDS(kDuDK);

	//sinh vien co diem tb cao nhat
	cSinhVien* dh = nullptr;
	cSinhVien* cd = nullptr;
	for (auto sv : danhSach)
	{
		if (sv->getLoaiSV())
		{
			if (dh == nullptr || dh->getDiemTB() < sv->getDiemTB())
				dh = sv;
		}
		else
		{
			if (cd == nullptr || cd->getDiemTB() < sv->getDiemTB())
				cd = sv;
		}
	}
	cout << "Sinh vien dai hoc co diem trung binh cao nhat\n";
	if (dh != nullptr)
	dh->xuat();
	cout << "\nSinh vien cao dang co diem trung binh cao nhat\n";
	if (cd != nullptr)
	cd->xuat();
	cout << endl;

	//so luong sinh vien khong du dieu kien 
	cout << "So sinh vien dai hoc khong du dieu kien tot nghiep la: " << dhK << " sinh vien\n";
	cout << "So sinh vien cao dang khong du dieu kien tot nghiep la: " << cdK << " sinh vien\n";

	for (auto sv : danhSach)
	{
		delete sv;
	}
	danhSach.clear();
	duDK.clear();
	kDuDK.clear();
	return 0;
}