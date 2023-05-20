#include <bits/stdc++.h>
using namespace std;

class QuanLy
{
    char maql[20];
    string hoten;

public:
    void nhap()
    {
        cout << "Nhap ma quan ly: ";
        fflush(stdin);
        gets(maql);
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
    }

    void xuat()
    {
        cout << "Ma quan ly: " << maql << endl;
        cout << "Ten quan ly: " << hoten << endl;
    }
};

class May
{
    char mamay[10];
    string kieumay;
    string tinhtrang;

public:
    void nhap()
    {
        cout << "Nhap ma may: ";
        fflush(stdin);
        gets(mamay);
        cout << "Nhap kieu may: ";
        fflush(stdin);
        getline(cin, kieumay);
        cout << "Nhap tinh trang may: ";
        fflush(stdin);
        getline(cin, tinhtrang);
    }

    void xuat()
    {
        cout << setw(10) << mamay << "\t" << setw(20) << kieumay << "\t" << setw(10) << tinhtrang << endl;
    }
};

class PhongMay
{
    char maphong[10];
    string tenphong;
    float dientich;
    QuanLy x;
    May *y;
    int n;

public:
    void nhap()
    {
    	x.nhap();
        cout << "Nhap ma phong: ";
        fflush(stdin);
        gets(maphong);
        cout << "Nhap ten phong: ";
        fflush(stdin);
        getline(cin, tenphong);
        cout << "Nhap dien tich phong: ";
        cin >> dientich;
        
        cout << "Nhap so luong may: ";
        cin >> n;
        y = new May[n];
        for (int i = 0; i < n; i++)
        {
            y[i].nhap();
        }
    }
    void xuat()
    {
        cout << "----- Thong tin ve phong may -----" << endl;
        x.xuat();
        cout << "Ma phong: " << maphong << endl;
        cout << "Ten phong: " << tenphong << endl;
        cout << "Dien tich phong: " << dientich << endl;
        
        cout << "\nDanh sach cac may trong phong" << endl;
        cout << setw(10) << "Ma may"
             << "\t" << setw(20) << "Kieu may"
             << "\t" << setw(10) << "Tinh trang" << endl;
        for (int i = 0; i < n; i++)
        {
            y[i].xuat();
        }
    }
};

int main()
{
    PhongMay pm1;
    pm1.nhap();
    pm1.xuat();
}