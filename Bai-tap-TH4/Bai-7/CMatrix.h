#pragma once
#include <iostream>
#include <vector>
using namespace std;

class CMatrix
{
private:
	int soHang, soCot;
	vector<vector<double>> maTran;
public:
	CMatrix();
	friend istream& operator>>(istream& in, CMatrix& maTran);
	friend ostream& operator<<(ostream& out, const CMatrix& maTran);
	CMatrix operator+(const CMatrix& other) const;
	CMatrix operator-(const CMatrix& other) const;
	CMatrix operator*(const CMatrix& other) const;
};

