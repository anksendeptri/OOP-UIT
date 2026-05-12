#include "cSoPhuc.h"
#include <iostream>
using namespace std;

int main()
{
	cSoPhuc A, B;
	cout << "Nhap so phuc A: \n";
	cin >> A; 
	cout << "Nhap so phuc B: \n";
	cin >> B;

	cout << "A = " << A << endl;
	cout << "B = " << B << endl;

	//tinh toan
	cout << "Tong: ";
	cout << A + B << endl;

	cout << "Hieu: ";
	cout << A - B << endl;

	cout << "Tich: ";
	cout << A * B << endl;

	cout << "Thuong: ";
	cout << A / B << endl;

	//so sanh
	if (A == B)
		cout << "A bang B\n";
	if (A != B)
		cout << "A khac B\n";
}