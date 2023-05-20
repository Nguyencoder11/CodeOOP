#include <bits/stdc++.h>
using namespace std;

class HANG
{
private:
    string Mahang;
    string Tenhang;
    long Dongia;
    int Soluong;

public:
    void nhap()
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        getline(cin, Mahang);
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, Tenhang);
        cout << "Nhap gia: ";
        cin >> Dongia;
        cout << "Nhap so luong: ";
        cin >> Soluong;
    }

    void xuat()
    {
        cout << setw(15) << Mahang << "\t" << setw(20) << Tenhang << "\t" << setw(20) << Dongia << "\t" << setw(10) << Soluong << "\t" << setw(15) << Dongia * Soluong << endl;
    }
};

int main()
{
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    HANG *a = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Mat hang thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "--- Thong ti ve cac mat hang ---" << endl;
    cout << setw(15) << "Ma Hang"
         << "\t" << setw(20) << "Ten Hang"
         << "\t" << setw(20) << "Don Gia"
         << "\t" << setw(10) << "So Luong"
         << "\t" << setw(15) << "Thanh tien" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}