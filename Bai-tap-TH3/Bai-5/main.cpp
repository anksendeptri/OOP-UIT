#include <iostream>
#include "cDaThuc.h"
using namespace std;

int main()
{
	cDaThuc A, B;
	cout << "Nhap da thuc A:" << endl;
		A.nhap();
	cout << endl;
	cout << "Nhap da thuc B:" << endl;
		B.nhap();
	cout << endl;
	cout << "Da thuc A: ";
		A.xuat();
	cout << endl;
	cout << "Da thuc B: ";
		B.xuat();
	cout << endl << endl;

	//tinh gia tri da thuc tai x
	cout << "Nhap vao x: ";
	double x;
	cin >> x;
	cout << "Gia tri da thuc A tai x = " << x << " la: " << A.tinhGiaTri(x) << endl;
	cout << "Gia tri da thuc B tai x = " << x << " la: " << B.tinhGiaTri(x) << endl;
	cout << endl;

	//tinh toan
	cout << "Tong hai da thuc A + B: ";
		A.congDaThuc(B).xuat();
		cout << endl;
	cout << "Hieu hai da thuc A - B: ";
		A.truDaThuc(B).xuat();
		cout << endl;
	return 0;
}
