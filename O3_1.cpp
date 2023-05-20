#include <bits/stdc++.h>
using namespace std;

class Array
{
private:
    float *value;
    int n;

public:
    friend istream &operator>>(istream &is, Array &arr)
    {
        do
        {
            cout << "Nhap so phan tu: ";
            is >> arr.n;
        } while (arr.n <= 0);
        arr.value = new float[arr.n];
        for (int i = 0; i < arr.n; i++)
        {
            cout << "Arr[" << i + 1 << "]: ";
            is >> arr.value[i];
        }
        return is;
    }

    friend ostream &operator<<(ostream &out, Array &arr)
    {
        for (int i = 0; i < arr.n; i++)
        {
            out << arr.value[i] << " ";
        }
        return out;
    }

    Array operator++();

    Array operator--();
};

Array Array::operator++()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (value[j] < value[j - 1])
            {
                float tg = value[j];
                value[j] = value[j - 1];
                value[j - 1] = tg;
            }
        }
    }
}

Array Array::operator--()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (value[j] > value[j - 1])
            {
                float tg = value[j];
                value[j] = value[j - 1];
                value[j - 1] = tg;
            }
        }
    }
}

int main()
{
    Array a;
    cout << "Nhap vao mang\n";
    cin >> a;
    cout << "Mang da nhap: " << a << endl;

    ofstream f("THO3_1.txt", ios::out);
    f << "Mang da nhap: " << a << endl;
    cout << "\nMang sap xep tang dan: ";
    ++a;
    cout << a;
    f << "\nMang sap xep tang dan: ";
    ++a;
    f << a;

    cout << "\nMang sap xep giam dan: ";
    --a;
    cout << a;
    f << "\nMang sap xep giam dan: ";
    --a;
    f << a;
    f.close();
}