#include <bits/stdc++.h>
using namespace std;

class NSX
{
private:
    string tenNSX, diachi;

public:
    friend class HANG;
    void nhap()
    {
        cout << "Ten NSX: ";
        fflush(stdin);
        getline(cin, tenNSX);
        cout << "Dia chi: ";
        fflush(stdin);
        getline(cin, diachi);
    }

    void xuat()
    {
        cout << setw(15) << tenNSX;
        cout << setw(20) << diachi;
    }
};

class HANG
{
protected:
    string tenhang;
    NSX x;
    int dongia;

public:
    void nhap()
    {
        cout << "Ten hang: ";
        fflush(stdin);
        getline(cin, tenhang);
        x.nhap();
        cout << "Don gia: ";
        cin >> dongia;
    }

    void xuat()
    {
        cout << setw(15) << tenhang;
        x.xuat();
        cout << setw(10) << dongia;
    }

    HANG()
    {
        tenhang = "Ti vi";
        dongia = 3000000;
    }
};

class DATE
{
private:
    int d, m, y;

public:
    friend class TIVI;
    void nhap()
    {
        cout << "Ngay nhap: ";
        cin >> d >> m >> y;
    }

    void xuat()
    {
        cout << setw(10) << d << "/" << m << "/" << y;
    }
};

class TIVI : public HANG
{
private:
    float kichthuoc;
    DATE ngaynhap;

public:
    void nhap()
    {
        HANG::nhap();
        ngaynhap.nhap();
        cout << "Kich thuoc: ";
        cin >> kichthuoc;
    }

    void xuat()
    {
        HANG::xuat();
        ngaynhap.xuat();
        cout << setw(12) << kichthuoc << endl;
    }

    TIVI() : HANG()
    {
        kichthuoc = 0.0;
    }
};

int main()
{
    TIVI x;
    x.nhap();
    cout << "=================================== THONG TIN TIVI VUA NHAP =====================================\n";
    cout << setw(15) << "Ten hang";
    cout << setw(15) << "Ten NSX";
    cout << setw(20) << "Dia chi";
    cout << setw(10) << "Don gia";
    cout << setw(17) << "Ngay nhap";
    cout << setw(15) << "Kich thuoc" << endl;
    x.xuat();
    cout << "=================================================================================================\n";
}