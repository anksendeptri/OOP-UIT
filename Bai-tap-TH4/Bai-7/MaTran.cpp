#include "CMatrix.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    CMatrix A, B;
    cout << "Nhap ma tran A: \n";
    cin >> A;
    cout << "Ma tran A:\n";
    cout << A;
    cout << "Nhap ma tran B: \n";
    cin >> B;
    cout << "Ma tran B:\n";
    cout << B;
    
    //tinh toan
	cout << "A + B:\n" << A + B;
    cout << "A - B:\n" << A - B;
	cout << "A * B:\n" << A * B;

    return 0;
}
