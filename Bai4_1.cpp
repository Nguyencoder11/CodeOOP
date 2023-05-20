#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string hoten;
    char ngaysinh[10];
    string quequan;
};

class KySu : public Person
{
private:
    string nganh;
    int NamTN;

public:
    void nhap()
    {
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap ngay sinh: ";
        fflush(stdin);
        gets(ngaysinh);
        cout << "Nhap que quan: ";
        fflush(stdin);
        getline(cin, quequan);
        cout << "Nhap nganh: ";
        fflush(stdin);
        getline(cin, nganh);
        cout << "Nhap namTN: ";
        cin >> NamTN;
    }

    void xuat()
    {
        cout << setw(20) << hoten << "\t" << setw(10) << ngaysinh << "\t" << setw(20) << quequan << "\t" << setw(20) << nganh << "\t" << setw(10) << NamTN << endl;
    }

    friend void NamTN_Max(KySu *a, int n);
};

void NamTN_Max(KySu *a, int n)
{
    int max = a[0].NamTN;
    for (int i = 0; i < n; i++)
    {
        if (a[i].NamTN > max)
        {
            max = a[i].NamTN;
        }
    }
    cout << "Danh sach ky su tot nghiep gan day nhat" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i].NamTN == max)
        {
            a[i].xuat();
        }
    }
}

int main()
{
    int n;
    cout << "Danh sach ky su: ";
    cin >> n;
    KySu *a = new KySu[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Ky su " << i + 1 << endl;
        a[i].nhap();
    }
    cout << setw(20) << "Ho ten"
         << "\t" << setw(10) << "Ngay sinh"
         << "\t" << setw(20) << "Que quan"
         << "\t" << setw(20) << "Nganh"
         << "\t" << setw(10) << "Nam TN" << endl;
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    
    NamTN_Max(a, n);
}