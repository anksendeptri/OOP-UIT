#include "CTime.h"
#include <iostream>
using namespace std;

int main()
{
    CTime tGian;
    cin >> tGian;
    cout << "Thoi gian hien tai: " << tGian; 
    cout << endl;
    cout << "Thoi gian 10 giay toi: " << tGian + 10;
    cout << endl;
    cout << "Thoi gian 1 giay sau: " << ++tGian;
	cout << endl; 
    cout << "Thoi gian 1 giay truoc " << --tGian;
}
