#include <bits/stdc++.h>
using namespace std;

class Tamthuc
{
private:
    float a, b, c;

public:
    Tamthuc()
    {
        a = b = c = 0;
    }

    Tamthuc(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    friend ostream &operator<<(ostream &out, Tamthuc &y)
    {
        out << y.a << "x^2 + " << y.b << "x + " << y.c << endl;
        return out;
    }

    Tamthuc operator+(Tamthuc y)
    {
        Tamthuc t;
        t.a = a + y.a;
        t.b = b + y.b;
        t.c = c + y.c;
        return t;
    }

    Tamthuc operator-(Tamthuc y)
    {
        Tamthuc t;
        t.a = a - y.a;
        t.b = b - y.b;
        t.c = c - y.c;
        return t;
    }

    // Phuong thuc toan tu doi dau tam thuc
    Tamthuc operator--()
    {
        return Tamthuc(-a, -b, -c);
    }
};

int main()
{
    Tamthuc t1(3, 7, 2), t2(-3, 5, 4);
    cout << "Tam thuc 1: " << t1;
    cout << "Tam thuc 2: " << t2;
    Tamthuc t3, t4;
    t3 = --t1;
    t4 = --t2;

    Tamthuc t5, t6;
    t5 = t1.operator+(t2);
    t6 = t1.operator-(t2);
    cout << "Doi dau tam thuc 1: " << t3;
    cout << "Doi dau tam thuc 2: " << t4;
    cout << "Tong 2 tam thuc: " << t5;
    cout << "Hieu 2 tam thuc: " << t6;

    ofstream f("Bai5_3.txt", ios::out);
    f << "Tam thuc 1: " << t1;
    f << "Tam thuc 2: " << t2;
    f << "Doi dau tam thuc 1: " << t3;
    f << "Doi dau tam thuc 2: " << t4;
    f << "Tong 2 tam thuc: " << t5;
    f << "Hieu 2 tam thuc: " << t6;
    f.close();
}