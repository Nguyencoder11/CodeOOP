#include <bits/stdc++.h>
using namespace std;

class SP
{
private:
    int a, b;

public:
    SP()
    {
        a = b = 0;
    }

    SP(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    friend ostream &operator<<(ostream &out, SP &y)
    {
        out << y.a << " + " << y.b << "*i" << endl;
        return out;
    }

    SP operator+(SP y)
    {
        SP c;
        c.a = a + y.a;
        c.b = b + y.b;
        return c;
    }

    SP operator-(SP y)
    {
        SP c;
        c.a = a - y.a;
        c.b = b - y.b;
        return c;
    }
};

int main()
{
    SP sp1(3, 4), sp2(1, 2);
    cout << "SP1: " << sp1;
    cout << "SP2: " << sp2;
    SP sp3, sp4;
    sp3 = sp1.operator+(sp2);
    sp4 = sp1.operator-(sp2);
    cout << "Tong 2 so phuc: " << sp3;
    cout << "Hieu 2 so phuc: " << sp4;

    ofstream f("Bai5_2.txt", ios::out);
    f << "SP1: " << sp1;
    f << "SP2: " << sp2;
    f << "Tong 2 so phuc: " << sp3;
    f << "Hieu 2 so phuc: " << sp4;
    f.close();
}