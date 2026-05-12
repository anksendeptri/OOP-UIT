#include <iostream>
#include "cPhanSo.h"
using namespace std;

int main()
{
	cPhanSo ps1, ps2;
	cout << "Nhap phan so 1: " << endl;
	cin >> ps1;
	cout << "Nhap phan so 2: " << endl;
	cin >> ps2;
	cout << "Phan so 1: " << ps1 << endl;
	cout << "Phan so 2: " << ps2 << endl;

	//tinh toan
	cout << ps1 << " + " << ps2 << " = " << ps1 + ps2 << endl;
	cout << ps1 << " - " << ps2 << " = " << ps1 - ps2 << endl;
	cout << ps1 << " * " << ps2 << " = " << ps1 * ps2 << endl;
	cout << ps1 << " / " << ps2 << " = " << ps1 / ps2 << endl;
	
	//so sanh
	if (ps1 == ps2) cout << ps1 << " = " << ps2 << endl;
	if (ps1 > ps2) cout << ps1 << " > " << ps2 << endl;
	if (ps1 < ps2) cout << ps1 << " < " << ps2 << endl;

	return 0;
}