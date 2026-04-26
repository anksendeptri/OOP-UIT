#pragma once
#include <vector>

using namespace std;
class cArray
{
private:
	vector<int> arr;
	int n;
public:
	cArray(int size = 0);
	void taoMangNgauNhien();
	void Xuat();
	int demSoLanXuatHien(int x);
	bool kiemTraTangDan();
	int timSoLeNhoNhat();
	int timSoNguyenToLonNhat();
	void sapXepTangDan();
	void sapXepGiamDan();
};

