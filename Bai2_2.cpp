#include <bits/stdc++.h>
using namespace std;

class NSX
{
    char maNSX[10];
    string tenNSX;
    string diaChi;

public:
    void nhap()
    {
        cout << "Nhap ma NSX: ";
        fflush(stdin);
        gets(maNSX);
        cout << "Nhap ten NSX: ";
        fflush(stdin);
        getline(cin, tenNSX);
        cout << "Nhap dia chi: ";
        fflush(stdin);
        getline(cin, diaChi);
    }

    void xuat()
    {
        cout << maNSX << "\t" << tenNSX << "\t" << diaChi;
    }
};

class HANG
{
    char maHang[10];
    string tenHang;
    NSX x;

public:
    void nhap()
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        gets(maHang);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, tenHang);
        x.nhap();
    }

    void xuat()
    {
        cout << maHang << "\t" << tenHang << "\t";
        x.xuat();
    }
};

int main()
{
    HANG a;
    a.nhap();
    a.xuat();
}