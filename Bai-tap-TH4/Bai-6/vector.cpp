#include <iostream>
#include <vector>
#include "CVector.h"
using namespace std;

int main()
{
	CVector A, B;
	cout << "Nhap vector A: \n";
	cin >> A;
	cout << "Nhap vector B: \n";
	cin >> B;
	cout << "Nhap x: ";
	double x;
	cin >> x;
	
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;

	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "A * " << x << " = " << A * x << endl;
	cout << "B * " << x << " = " << B * x << endl;
	return 0;
}