//Bài tập 4: Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
#include <iostream>
using namespace std;
// ham kiem tra nam nhuan
bool namNhuan(y)
{
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return 1;
    else return 0;
}
// kiem tra so ngay trong thang m
int soNgay(int m, int y)
{
    switch (m)
    {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return namNhuan(y) ? 29 : 28;
        default: return 31;
    }
}
// ham nhap
void Nhap(int &d, int &m, int &y)
{
    //neu nhap ky tu la hoac ngay khong hop le thi nhap lai
    while(!(cin >> d >> m >> y) || d < 1 || d > soNgay(m, y) || m < 1 || m > 12 || y < 1)
    {
        cout << "Nhap sai! Yeu cau nhap lai:\n";
    }
}
int main()
{
    int d, m, y;
    return 0;
}