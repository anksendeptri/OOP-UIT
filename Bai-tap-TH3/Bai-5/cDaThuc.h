#pragma once
#include <vector>
using namespace std;

class cDaThuc
{
private:
	int bac;
	vector<double> heSo;
public:
	cDaThuc(int b = 0);
	double tinhGiaTri(double x);
	void nhap();
	void xuat();
	cDaThuc congDaThuc(cDaThuc dt);
	cDaThuc truDaThuc(cDaThuc dt);
};

