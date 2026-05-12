#pragma once
#include <iostream>
using namespace std;

class cSoPhuc
{
private:
    double dThuc, dAo;
public:
    cSoPhuc(double thuc = 0, double ao = 0);
    friend istream& operator >>(istream& is, cSoPhuc& sp);
    friend ostream& operator <<(ostream& os, const cSoPhuc& sp);
    cSoPhuc operator +(const cSoPhuc& B) const;
    cSoPhuc operator -(const cSoPhuc& B) const;
    cSoPhuc operator *(const cSoPhuc& B) const;
    cSoPhuc operator /(const cSoPhuc& B) const;
	bool operator ==(const cSoPhuc& B) const;
	bool operator !=(const cSoPhuc& B) const;
};
