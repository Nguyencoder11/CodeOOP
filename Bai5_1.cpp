#include <bits/stdc++.h>
using namespace std;

class PS
{
private:
    int Tuso, Mauso;

public:
    friend istream &operator>>(istream &is, PS &ps)
    {
        cout << "Tu so: ";
        is >> ps.Tuso;
        cout << "Mau so: ";
        is >> ps.Mauso;
        return is;
    }

    friend ostream &operator<<(ostream &os, PS ps)
    {
        os << ps.Tuso << "/" << ps.Mauso;
        return os;
    }

    PS operator*(PS b)
    {
        PS c;
        c.Tuso = Tuso * b.Tuso;
        c.Mauso = Mauso * b.Mauso;
        return c;
    }

    PS operator/(PS b)
    {
        PS c;
        c.Tuso = Tuso * b.Mauso;
        c.Mauso = Mauso * b.Tuso;
        return c;
    }

    PS operator+(PS b)
    {
        PS c;
        c.Tuso = Tuso * b.Mauso + Mauso * b.Tuso;
        c.Mauso = Mauso * b.Mauso;
        return c;
    }

    PS operator-(PS b)
    {
        PS c;
        c.Tuso = Tuso * b.Mauso - Mauso * b.Tuso;
        c.Mauso = Mauso * b.Mauso;
        return c;
    }

    float operator--()
    {
        return (float)Tuso / Mauso;
    }
};

int main()
{
    PS a, b;
    cout << "Nhap phan so A: \n";
    cin >> a;

    cout << "Nhap phan so B: \n";
    cin >> b;
    cout << "----- CAC PHAN SO DA NHAP -----\n";
    cout << "Phan so A: ";
    cout << a << endl;
    cout << "Phan so B: ";
    cout << b << endl;

    PS p1, p2, p3, p4;
    p1 = a * b;
    p2 = a / b;
    p3 = a + b;
    p4 = a - b;

    cout << "Tich 2 phan so: " << p1 << endl;
    cout << "Gia tri cua tich: " << --p1 << endl;
    cout << "Thuong 2 phan so: " << p2 << endl;
    cout << "Gia tri cua thuong: " << --p2 << endl;
    cout << "Tong 2 phan so: " << p3 << endl;
    cout << "Gia tri cua tong: " << --p3 << endl;
    cout << "Hieu 2 phan so: " << p4 << endl;
    cout << "Gia tri cua hieu: " << --p4 << endl;

    ofstream f("Bai5_1.txt", ios::out);
    f << "----- CAC PHAN SO DA NHAP -----\n";
    f << "Phan so A: ";
    f << a << endl;
    f << "Phan so B: ";
    f << b << endl;
    f << "Tich 2 phan so: " << p1 << endl;
    f << "Gia tri cua tich: " << --p1 << endl;
    f << "Thuong 2 phan so: " << p2 << endl;
    f << "Gia tri cua thuong: " << --p2 << endl;
    f << "Tong 2 phan so: " << p3 << endl;
    f << "Gia tri cua tong: " << --p3 << endl;
    f << "Hieu 2 phan so: " << p4 << endl;
    f << "Gia tri cua hieu: " << --p4 << endl;
    f.close();
}
