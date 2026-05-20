#include "cNVSX.h"
#include "cNVVP.h"
#include <vector>
#pragma once
class cCongTy
{
private:
	std::vector<cNhanVien*> danhSachNV;
public: 
	void nhapDanhSach();
	void xuatDanhSach();
	long long tongLuong();
	cNhanVien* getMinLuong();
	cNhanVien* getMaxTuoi();
	~cCongTy();	
};

