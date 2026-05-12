#pragma once
#include <vector>
#include <iostream>
using namespace std;
class CVector
{
private:
	int iSoChieu;
	vector<double> toaDo;
public:
	CVector(int chieu = 0, vector<double> td = {});
	friend istream& operator>>(istream& is, CVector& vtor);
	friend ostream& operator<<(ostream& os, CVector vtor);
	CVector operator+(CVector other);
	CVector operator-(CVector other);
	CVector operator*(double x);
	double operator*(CVector other);
	double tinhDoDai();
};

