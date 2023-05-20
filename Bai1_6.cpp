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

    int Max()
    {
        int max = a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        return max;
    }

    int Min()
    {
        int min = a[0];
        for (int i = 0; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
            }
        }
        return min;
    }
};

int main()
{
    Array a1(5);
    a1.nhap();
    a1.xuat();
    cout<< "Max: " << a1.Max() << endl;
    cout<< "Min: " << a1.Min();
    a1.~Array();
}