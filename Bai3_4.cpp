#include <bits/stdc++.h>
using namespace std;

class Ptb2
{
private:
    int a, b, c;

public:
    void nhap()
    {
        cout << "Nhap a, b, c: ";
        cin >> a >> b >> c;
    }

    void xuat()
    {
        cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    }

    void giai()
    {
        if (a == 0)
        {
            if (b == 0 && c == 0)
            {
                cout << "Phuong trinh vo so nghiem";
            }
            else if (b == 0 && c != 0)
            {
                cout << "Vo nghiem";
            }
            else
            {
                cout << "x = " << (float)-c / b;
            }
        }
        else
        {
            int delta = b * b - 4 * a * c;
            if (delta > 0)
            {
                cout << "x1 = " << (float)(-b + sqrt(delta)) / (2 * a) << endl;
                cout << "x2 = " << (float)(-b - sqrt(delta)) / (2 * a);
            }
            else if (delta == 0)
            {
                cout << "x1 = x2 = " << (float)-b / (2 * a);
            }
            else
            {
                cout << "Vo nghiem";
            }
        }
    }

    Ptb2()
    {
        a = b = c = 0;
    }

    Ptb2(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
};

int main()
{
    Ptb2 p, q(6, 8, 10);
    cout << "----- Cac phuong trinh khoi tao khong doi -----\n";
    cout << "Phuong trinh bac 2 p: ";
    p.xuat();
    p.giai();
    cout << "\n";
    cout << "----- Phuong trinh khoi tao co doi -----\n";
    cout << "Phuong trinh bac 2 q: ";
    q.xuat();
    q.giai();
    cout << "\n";

    Ptb2 t;
    t.nhap();
    cout << "Phuong trinh bac 2 t: ";
    t.xuat();
    t.giai();
}