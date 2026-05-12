#include "CMatrix.h"
#include <iostream>
#include <vector>
using namespace std;

// constructor
CMatrix::CMatrix() : soHang(0), soCot(0), maTran(0, vector<double>(0, 0)) {}

// operator nhap
istream& operator>>(istream& is, CMatrix& MT)
{
	cout << "Nhap so hang va so cot: ";
	is >> MT.soHang >> MT.soCot;
	MT.maTran.resize(MT.soHang, vector<double>(MT.soCot));
	cout << "Nhap cac phan tu cua ma tran:\n";
	for (int i = 0; i < MT.soHang; ++i)
		for (int j = 0; j < MT.soCot; ++j)
			is >> MT.maTran[i][j];
	return is;
}

//operator xuat
ostream& operator<<(ostream& os, const CMatrix& MT)
{
	for (int i = 0; i < MT.soHang; ++i)
	{
		cout << "| ";
		for (int j = 0; j < MT.soCot; ++j)
			os << MT.maTran[i][j] << " ";
		cout << "|";
		os << endl;
	}
	return os;
}

// operator cong
// input: 1  ma tran khac | output: ma tran ket qua
// cong hai ma tran chi duoc thuc hien khi chung co cung kich thuoc
CMatrix CMatrix::operator+(const CMatrix& other) const
{
	CMatrix result;
	if (soHang != other.soHang || soCot != other.soCot)
	{
		cout << "Khong the cong hai ma tran khac kich thuoc!" << endl;
		return result;
	}
	result.soHang = soHang;
	result.soCot = soCot;
	result.maTran.resize(soHang, vector<double>(soCot));
	for (int i = 0; i < soHang; ++i)
		for (int j = 0; j < soCot; ++j)
			result.maTran[i][j] = maTran[i][j] + other.maTran[i][j];
	return result;
}

// operator tru
// input: 1  ma tran khac | output: ma tran ket qua
// tru hai ma tran chi duoc thuc hien khi chung co cung kich thuoc
CMatrix CMatrix::operator-(const CMatrix& other) const
{
	CMatrix result;
	if (soHang != other.soHang || soCot != other.soCot)
	{
		cout << "Khong the tru hai ma tran khac kich thuoc!" << endl;
		return result;
	}
	result.soHang = soHang;
	result.soCot = soCot;
	result.maTran.resize(soHang, vector<double>(soCot));
	for (int i = 0; i < soHang; ++i)
		for (int j = 0; j < soCot; ++j)
			result.maTran[i][j] = maTran[i][j] - other.maTran[i][j];
	return result;
}

// operator nhan
// input: 1  ma tran khac | output: ma tran ket qua
// nhan hai ma tran chi duoc thuc hien khi so cot cua ma tran thu nhat bang so hang cua ma tran thu hai
CMatrix CMatrix::operator*(const CMatrix& other) const
{
	CMatrix result;
	if (soCot != other.soHang)
	{
		cout << "Khong the nhan hai ma tran khac kich thuoc!" << endl;
		return result;
	}
	result.soHang = soHang;
	result.soCot = other.soCot;
	result.maTran.resize(result.soHang, vector<double>(result.soCot, 0));
	for (int i = 0; i < result.soHang; ++i)
		for (int j = 0; j < result.soCot; ++j)
			for (int k = 0; k < soCot; ++k)
				result.maTran[i][j] += maTran[i][k] * other.maTran[k][j];
	return result;
}