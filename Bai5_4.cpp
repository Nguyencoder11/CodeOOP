#include <bits/stdc++.h>
using namespace std;

class Matran
{
private:
    int n, m;
    double a[100][100];

public:
    friend istream &operator>>(istream &is, Matran &y)
    {
        cout << "So dong: ";
        is >> y.n;
        cout << "So cot: ";
        is >> y.m;
        for (int i = 0; i < y.n; i++)
        {
            for (int j = 0; j < y.m; j++)
            {
                cout << "a[" << i << "][" << j << "]: ";
                is >> y.a[i][j];
            }
        }

        return is;
    }

    friend ostream &operator<<(ostream &out, Matran &y)
    {
        for (int i = 0; i < y.n; i++)
        {
            for (int j = 0; j < y.m; j++)
            {
                out << y.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Phuong thuc toan tu doi dau ma tran
    Matran operator--()
    {
        Matran result;
        result.n = n;
        result.m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result.a[i][j] = -a[i][j];
            }
        }
        return result;
    }

    // Phuong thuc cong 2 ma tran
    Matran operator+(Matran matrix)
    {
        if (n != matrix.n || m != matrix.m)
        {
            cout << "Kich thuoc khong phu hop!\n";
        }
        Matran result;
        result.n = n;
        result.m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result.a[i][j] = a[i][j] + matrix.a[i][j];
            }
        }
        return result;
    }

    // Phuong thuc tru 2 ma tran
    Matran operator-(Matran matrix)
    {
        if (n != matrix.n || m != matrix.m)
        {
            cout << "Kich thuoc khong phu hop!\n";
        }
        Matran result;
        result.n = n;
        result.m = m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                result.a[i][j] = a[i][j] - matrix.a[i][j];
            }
        }
        return result;
    }
};

int main()
{
    Matran P, Q;
    cout << "Ma tran P: " << endl;
    cin >> P;
    cout << "Ma tran Q: " << endl;
    cin >> Q;

    cout << "----- Ma tran P -----\n";
    cout << P;
    cout << "----- Ma tran Q -----\n";
    cout << Q;

    Matran P1, Q1;
    P1 = --P;
    Q1 = --Q;
    cout << "--- Doi dau ma tran P ---\n";
    cout << P1 << endl;
    cout << "--- Doi dau ma tran Q ---\n";
    cout << Q1 << endl;

    Matran sum = P1 + Q1;
    Matran diff = P1 - Q1;
    cout << "--- Tong ma tran P1 va Q1 ---\n";
    cout << sum << endl;
    cout << "--- Hieu ma tran P1 va Q1 ---\n";
    cout << diff << endl;

    ofstream f("Bai5_4.txt", ios::out);
    f << "----- Ma tran P -----\n";
    f << P;
    f << "----- Ma tran Q -----\n";
    f << Q;
    f << "--- Doi dau ma tran P ---\n";
    f << P1 << endl;
    f << "--- Doi dau ma tran Q ---\n";
    f << Q1 << endl;
    f << "--- Tong ma tran P1 va Q1 ---\n";
    f << sum << endl;
    f << "--- Hieu ma tran P1 va Q1 ---\n";
    f << diff << endl;
    f.close();
}