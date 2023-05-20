#include <bits/stdc++.h>
using namespace std;

class HANG
{
    char mahang[10];
    string tenhang;
    long dongia;

public:
    void nhap()
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        gets(mahang);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, tenhang);
        cout << "Nhap don gia: ";
        cin >> dongia;
    }

    void xuat()
    {
        cout << setw(10) << mahang << "\t" << setw(15) << tenhang << "\t" << setw(20) << dongia << endl;
    }
};

class PHIEU
{
    char maphieu[10];
    int n;
    HANG x[100];

public:
    void nhap()
    {
        cout << "Nhap ma phieu: ";
        fflush(stdin);
        gets(maphieu);
        cout << "Nhap so luong hang: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            x[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(10) << maphieu;
        cout << "\nDanh sach hang da nhap" << endl;
        cout << setw(10) << "Ma hang"
             << "\t" << setw(15) << "Ten hang"
             << "\t" << setw(20) << "Don gia" << endl;
        for (int i = 0; i < n; i++)
        {
            x[i].xuat();
        }
    }
};

int main()
{
    PHIEU p;
    p.nhap();
    cout << setw(10) << "Ma phieu: ";
    p.xuat();
}