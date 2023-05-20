#include <bits/stdc++.h>
using namespace std;

class NSX
{
private:
    char maNSX[10];
    string tenNSX;
    string DcNSX;

public:
    friend class HANG;
};

class HANG
{
private:
    char mahang[20];
    string tenhang;
    long dongia;
    float trongluong;
    NSX x;

public:
    void nhap()
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        gets(mahang);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, tenhang);
        cout << "Nhap ma NSX: ";
        fflush(stdin);
        gets(x.maNSX);
        cout << "Nhap ten NSX: ";
        fflush(stdin);
        getline(cin, x.tenNSX);
        cout << "Nhap dia chi: ";
        fflush(stdin);
        getline(cin, x.DcNSX);
        cout << "Nhap don gia: ";
        cin >> dongia;
        cout << "Nhap trong luong: ";
        cin >> trongluong;
    }

    void xuat()
    {
        cout << setw(10) << mahang << setw(20) << tenhang << setw(10) << x.maNSX << setw(20) << x.tenNSX << setw(20) << x.DcNSX << setw(15) << dongia << setw(12) << trongluong << endl;
    }
};

int main()
{
    HANG h1;
    h1.nhap();
    cout << setw(10) << "Ma hang" << setw(20) << "Ten hang" << setw(10) << "Ma NSX" << setw(20) << "Ten NSX" << setw(20) << "Dia chi" << setw(15) << "Don gia" << setw(12) << "Trong luong" << endl;
    h1.xuat();
}