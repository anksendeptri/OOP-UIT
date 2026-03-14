/*Bài tập 5: Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính
điểm trung bình và xuất kết quả*/
#include <iostream>
using namespace std;

//ham kiem tra ten
bool tenSai(string t)
{
    // vong lap chay het chuoi t
    for (char i : t)
    {
        //ten chi chua chu cai va dau cach
        if (!(i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' || i == ' '))
        return 1;
    }
    return 0;
}

//ham nhap
void Nhap(string &t, float &T, float &V)
{
    // nhap ten
    do
    {
    cout << "Nhap ho va ten: \n";
    getline(cin, t);
    } while(tenSai(t));

    // nhap diem
    cout << "Nhap diem toan va diem van: \n";
    while (!(cin >> T >> V) || T < 0 || T > 10 || V < 0 || V > 10)
    {
        cout << "Nhap sai! Yeu cau nhap lai! \n";
        // xoa loi nhap
        cin.clear();
        cin.ignore(100, '\n');
    }
}

int main()
{
    string t;
    float T, V;
    Nhap(t, T, V);
    // tinh diem trung binh
    float tb = (T + V) / 2;
    cout << "Diem trung binh cua " << t << " la : " << tb << endl;
    return 0;
}