#pragma once
#include <vector>
#include <iostream>
using namespace std;	

class CDaThuc
{
private:
	int bac;
	std::vector<double> heSo;
public:
	CDaThuc(int bac = 0, std::vector<double> heSo = {});
	friend istream& operator >>(istream& is, CDaThuc& dt);
	friend ostream& operator <<(ostream& os, const CDaThuc& dt);
	double tinhGiaTri(double x);
	CDaThuc operator +(const CDaThuc& dt);
	CDaThuc operator -(const CDaThuc& dt);
};	

