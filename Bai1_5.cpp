#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    int *a;
    int n;

public:
    Array(int size)
    {
        n = size;
        a = new int[n];
    }
    ~Array()
    {
        n = 0;
        delete[] a;
    }

    void nhap()
    {
        cout << "Nhap vao " << n << " phan tu cua mang:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    void xuat()
    {
        cout << "Cac phan tu cua mang la:\n";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void swap_asc()
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (a[j] < a[j - 1])
                {
                    int tmp = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = tmp;
                }
            }
        }
    }
};

int main()
{
    Array a1(5);
    a1.nhap();
    a1.swap_asc();
    a1.xuat();
    a1.~Array();
}