#include <bits/stdc++.h>
using namespace std;

class DATE
{
    int d, m, y;

public:
    void nhap()
    {
        cout << "Nhap ngay sinh: ";
        cin >> d >> m >> y;
    }

    void xuat()
    {
        cout << setw(10) << d << "/" << m << "/" << y;
    }
};

class NHANSU
{
    string maNhanSu;
    string Hoten;
    DATE NS;

public:
    void nhap()
    {
        cout << "Nhap ma nhan su: ";
        fflush(stdin);
        getline(cin, maNhanSu);
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, Hoten);
        NS.nhap();
    }

    void xuat()
    {
        cout << setw(12) << maNhanSu << "\t" << setw(15) << Hoten << "\t";
        NS.xuat();
    }
};

int main()
{
    NHANSU x;
    x.nhap();
    cout << "----- Thong tin nhan su -----" << endl;
    cout << setw(12) << "Ma nhan su" << "\t" << setw(15) << "Ho ten" << "\t" << setw(18) << "Ngay sinh" << endl;
    x.xuat();
}