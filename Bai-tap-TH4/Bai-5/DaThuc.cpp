#include "CDaThuc.h"
#include <iostream>
using namespace std;

int main()
{
	// nhap xuat
	CDaThuc A, B;
	cout << "Nhap vao da thuc A: \n";
	cin >> A;
	cout << "Nhap vao da thuc B: \n";
	cin >> B;
	cout << "Da thuc A: " << A << endl;
	cout << "Da thuc B: " << B << endl;
	
	// tinh gia tri
	double x;
	cout << "Nhap vao x: ";
	cin >> x;
	cout << endl;
	cout << "Gia tri cua da thuc A tai x = " << x << " la: ";
	cout << A.tinhGiaTri(x);
	cout << endl;
	cout << "Gia tri cua da thuc B tai x = " << x << " la: ";
	cout << B.tinhGiaTri(x);
	cout << endl;

	// tinh toan giua cac da thuc
	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	return 0;
}
