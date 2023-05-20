#include <bits/stdc++.h>
using namespace std;

class Phanso
{
private:
    int Tuso, Mauso;

public:
    Phanso()
    {
        Tuso = 1;
        Mauso = 2;
    }

    Phanso(int Tuso, int Mauso)
    {
        this->Tuso = Tuso;
        this->Mauso = Mauso;
    }

    friend istream &operator>>(istream &is, Phanso &ps)
    {
        cout << "Tu so: ";
        is >> ps.Tuso;
        cout << "Mau so: ";
        is >> ps.Mauso;
        return is;
    }

    friend ostream &operator<<(ostream &os, Phanso ps)
    {
        os << ps.Tuso << "/" << ps.Mauso;
        return os;
    }

    Phanso operator*(Phanso y)
    {
        Phanso c;
        c.Tuso = Tuso * y.Tuso;
        c.Mauso = Mauso * y.Mauso;
        return c;
    }

    float operator++()
    {
        return (float)Tuso / Mauso;
    }
};

int main()
{
    Phanso a, b;
    cout << "Nhap phan so A\n";
    cin >> a;
    cout << "Nhap phan so B\n";
    cin >> b;
    Phanso c = a.operator*(b);
    cout << "Tich cua A va B: " << c << endl;
    ofstream f("PHANSO.txt", ios::out);
    f << "Phan so A: " << a << endl;
    f << "Phan so B: " << b << endl;
    f << "Tich cua A va B: " << c << endl;
    f << "Gia tri cua phan so tich: " << ++c << endl;
    f.close();
}