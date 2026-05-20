#include "cCongTy.h"
#include "cNVVP.h"
#include "cNVSX.h"
#include <iostream>
#include <sstream>
using namespace std;

cCongTy::~cCongTy()
{
	for (cNhanVien* nv : danhSachNV)
	{
		if (nv != nullptr)
			delete nv;
		danhSachNV.clear();
	}
}

void cCongTy::nhapDanhSach()
{
	bool flag;	
	do
	{
		flag = 0;
		cout << "Chon loai nhan vien: \n";
		cout << "0: nhan vien san xuat\n";
		cout << "1: nhan vien van phong\n";
		bool loai;
		cin >> loai;
		cin.ignore();
		cNhanVien* nv = nullptr;
		if (loai)
			nv = new cNVVP();
		else
			nv = new cNVSX();
		nv->nhap();
		nv->getLuong();
		danhSachNV.push_back(nv);
		cout << "----------------------------------------------------------\n";
		cout << "Ban muon them nhan vien? (1: co , 0: khong)\n";
		cin >> flag;
	} while (flag);
}

void cCongTy::xuatDanhSach()
{
	cout << "Ho va ten\t\t | " << "Ngay sinh \t | " << "Luong\n";
	for (int i = 0; i < danhSachNV.size(); i++)
	{
		danhSachNV[i]->xuat();
		cout << endl;
	}
}

long long cCongTy::tongLuong()
{
	long long t = 0;
	for (int i = 0; i < danhSachNV.size(); i++)
		t += danhSachNV[i]->getLuong();
	return t;
}

cNhanVien* cCongTy::getMinLuong()
{
	cNhanVien* temp = nullptr;
	for (cNhanVien* nv : danhSachNV)
	{
		if (nv->getLoaiNV() == 0)
		{
			if (temp == nullptr || temp->getLuong() > nv->getLuong())
				temp = nv;
		}
	}
	return temp;
}

cNhanVien* cCongTy::getMaxTuoi()
{
	cNhanVien* temp = nullptr;
	for (cNhanVien* nv : danhSachNV)
	{
		if (nv->getLoaiNV() == 1)
		{
			if (temp == nullptr || nv->tinhTrongSoNgaySinh() < temp->tinhTrongSoNgaySinh())
				temp = nv;
		}
	}
	return temp;
}