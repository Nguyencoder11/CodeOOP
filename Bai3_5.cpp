#include <bits/stdc++.h>
using namespace std;

class ARRAY
{
    int n;
    int *VALUE;

public:
    ARRAY()
    {
        n = 0;
    }

    ARRAY(int a)
    {
        n = a;
        VALUE = new int[n];
        for (int i = 0; i < n; i++)
        {
            VALUE[i] = 0;
        }
    }

    ~ARRAY()
    {
        n = 0;
        delete[] VALUE;
    }

    void nhap()
    {
        if (n == 0)
        {
            cout << "\nNhap n: ";
            cin >> n;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> VALUE[i];
        }
    }

    void xuat()
    {
        cout << "Cac phan tu cua mang la:\n";
        for (int i = 0; i < n; i++)
        {
            cout << VALUE[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    ARRAY arr(5);
    cout << "----- Mang khoi tao khong doi -----\n";
    arr.xuat();

    cout << "----- Mang khoi tao co doi -----\n";
    arr.nhap();
    arr.xuat();
    arr.~ARRAY();
}