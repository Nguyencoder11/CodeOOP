#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    float a[100][100];
    int col;
    int row;

public:
    friend istream &operator>>(istream &is, Matrix &arr)
    {
        do
        {
            cout << "So dong: ";
            is >> arr.row;
            cout << "So cot: ";
            is >> arr.col;
        } while (arr.row <= 0 || arr.col <= 0);
        for (int i = 0; i < arr.row; i++)
        {
            for (int j = 0; j < arr.col; j++)
            {
                cout << "a[" << i << "][" << j << "]: ";
                is >> arr.a[i][j];
            }
        }
        return is;
    }

    friend ostream &operator<<(ostream &out, Matrix &arr)
    {
        for (int i = 0; i < arr.row; i++)
        {
            for (int j = 0; j < arr.col; j++)
            {
                out << arr.a[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // Chuyen vi ma tran
    Matrix operator++()
    {
        Matrix transpose;
        transpose.row = this->col;
        transpose.col = this->row;

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                transpose.a[j][i] = this->a[i][j];
            }
        }
        return transpose;
    }
};

int main()
{
    Matrix matrix, transpose;
    cout << "Nhap ma tran thuc:\n";
    cin >> matrix;
    cout << "Nhap ma tran nguyen:\n";
    cin >> transpose;
    cout << "Ma tran thuc vua nhap: \n";
    cout << matrix;
    cout << "Ma tran nguyen vua nhap: \n";
    cout << transpose;
    Matrix doubleMatrix = ++matrix;
    Matrix intMatrix = ++transpose;
    cout << "Ma tran thuc chuyen vi:\n";
    cout << doubleMatrix;
    cout << "Ma tran nguyen chuyen vi:\n";
    cout << intMatrix;

    ofstream f("THO3_3.txt", ios::out);
    f << "Ma tran thuc vua nhap: \n";
    f << matrix;
    f << "Ma tran nguyen vua nhap: \n";
    f << transpose;
    f << "Ma tran thuc chuyen vi:\n";
    f << doubleMatrix;
    f << "Ma tran nguyen chuyen vi:\n";
    f << intMatrix;
}