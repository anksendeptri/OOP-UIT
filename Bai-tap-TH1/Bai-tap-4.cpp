//Bài tập 4: Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
#include <iostream>
using namespace std;
// ham kiem tra nam nhuan
bool namNhuan(int y)
{
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
    return 0;
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
    while(!(cin >> d >> m >> y) || m < 1 || m > 12 || y < 1 || d < 1 || d > soNgay(m, y))
    {
        cout << "Nhap sai! Yeu cau nhap lai:\n";
        //xoa loi nhap va ky tu loi
        cin.clear();
        cin.ignore(100, '\n');
    }
}

// ham xuat ngay ke tiep
void nextDay(int d, int m, int y)
{
    d++;
    // neu vuot qua so ngay thi qua thang moi
    if (d > soNgay(m, y))
    {
        d = 1;
        m ++;
    }
    //thang vuot qua 12 thi qua nam moi
    if(m > 12)
    {
        m = 1;
        y++;
    }
    cout << d << "/" << m << "/" << y << endl;
}
int main()
{
    int d, m, y;
    cout << "Nhap ngay thang nam: \n";
    Nhap(d, m, y);
    nextDay(d, m, y);
    return 0;
}
