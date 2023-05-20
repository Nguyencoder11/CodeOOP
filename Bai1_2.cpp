#include <bits/stdc++.h>
using namespace std;

class HCN
{
    float d, r;

public:
    void nhap()
    {
        cout << "Nhap chieu dai va chieu rong: ";
        cin >> d >> r;
    }

    void ve()
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cout << "*"
                     << " ";
            }
            cout << endl;
        }
    }

    float Dientich()
    {
        return d * r;
    }

    float Chuvi()
    {
        return (d + r) * 2;
    }
};

int main()
{
    HCN x;
    x.nhap();
    x.ve();
    cout << "Dien tich = " << x.Dientich() << endl;
    cout << "Chu vi = " << x.Chuvi();
}
