#include <bits/stdc++.h>
using namespace std;

class Hang;
class Date
{
private:
    int d, m, y;

public:
    friend class Hang;
    friend void In_2017(Hang *a, int n);
};

class Hang
{
private:
    char mahang[10];
    string tenhang;
    Date ngaysx;

public:
    void nhap()
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        gets(mahang);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, tenhang);
        cout << "Nhap ngay san xuat: ";
        cin >> ngaysx.d >> ngaysx.m >> ngaysx.y;
    }

    void xuat()
    {
        cout << setw(10) << mahang << "\t" << setw(20) << tenhang << " \t" << setw(10) << right << ngaysx.d << "/" << ngaysx.m << "/" << ngaysx.y << endl;
    }
    friend void In_2017(Hang *a, int n);
};

void In_2017(Hang *a, int n)
{
    cout << "Danh sach hang san xuat nam 2017" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].ngaysx.y == 2017)
        {
            a[i].xuat();
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so luong hang: ";
    cin >> n;
    Hang *a = new Hang[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Hang thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "===== Danh sach hang da nhap =====\n"
         << endl;
    cout << setw(10) << "Ma hang"
         << "\t" << setw(20) << "Ten hang"
         << " \t" << setw(15) << right << "Ngay sx" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    In_2017(a, n);
}