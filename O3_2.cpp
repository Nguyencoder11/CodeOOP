#include <bits/stdc++.h>
using namespace std;

class Triangle
{
private:
    float a, b, c;

public:
    float operator++()
    {
        return a + b + c;
    }

    friend istream &operator>>(istream &is, Triangle &y)
    {
        is >> y.a >> y.b >> y.c;
        return is;
    }

    friend ostream &operator<<(ostream &out, Triangle &y)
    {
        out << "Ba canh tam giac: " << y.a << " " << y.b << " " << y.c << endl;
        out << "Chu vi: " << ++y << endl;
        return out;
    }
};
int main()
{
    Triangle P, Q;
    cout << "Nhap tam giac P" << endl;
    cin >> P;
    cout << "Nhap tam giac Q" << endl;
    cin >> Q;
    cout << P;
    cout << Q;
    ofstream f("THO3_2.txt", ios::out);
    f << "1. Tam giac P" << endl;
    f << P << endl;
    f << "2. Tam giac Q" << endl;
    f << Q << endl;
    f.close();
}