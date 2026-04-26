#include "cArray.h"
#include <iostream>

using namespace std;

int main()
{
	cArray A; 
	A.taoMangNgauNhien();
	cout << "Mang ngau nhien: \n";
	A.Xuat();
	cout << endl << endl;
	cout << "Nhap so can dem:  ";
	int x;
	cin >> x;
	cout << x << " xuat hien trong mang " << A.demSoLanXuatHien(x) << " lan.\n\n";

	if (A.kiemTraTangDan())
		cout << "Mang tang dan.\n";
	else
		cout << "Mang khong tang dan.\n";

	cout << endl;
	cout << "So le nho nhat trong mang: " << A.timSoLeNhoNhat() << endl;
	cout << "So nguyen to lon nhat trong mang: " << A.timSoNguyenToLonNhat() << endl << endl;
	cout << "Mang sau khi sap xep tang dan: \n";
	A.sapXepTangDan();
	A.Xuat();
	
	cout << endl <<	endl;
	cout << "Mang sau khi sap xep giam dan: \n";
	A.sapXepGiamDan();
	A.Xuat();
	cout << endl;
	return 0;
}