#include <bits/stdc++.h>
#define max 100
using namespace std;

class KHOA
{
private:
    string makhoa, tenkhoa, truongkhoa;

public:
    friend void xoa_Khoa(TRUONGDH a, int n);

public:
    friend class TRUONGDH;
};

class BAN
{
private:
    string maban, tenban, ngaythanhlap;

public:
    friend class TRUONGDH;
};

class TRUONG
{
protected:
    string matruong, tentruong, diachi;

public:
    void nhap()
    {
        cout << "Nhap ma truong: ";
        fflush(stdin);
        getline(cin, matruong);
        cout << "Ten truong: ";
        fflush(stdin);
        getline(cin, tentruong);
        cout << "Dia chi: ";
        fflush(stdin);
        getline(cin, diachi);
    }

    void xuat()
    {
        cout << setw(15) << left << "Ma truong: " << setw(10) << matruong << endl;
        cout << setw(20) << left << "Ten truong: " << setw(15) << tentruong << endl;
        cout << setw(20) << left << "Dia chi: " << setw(20) << diachi << endl;
    }
};

class TRUONGDH : public TRUONG
{
private:
    KHOA x[max];
    int n;
    BAN y[max];
    int m;

public:
    void nhap()
    {
        TRUONG::nhap();
        cout << "So khoa: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "Khoa thu " << i + 1 << endl;
            cout << "Ma khoa: ";
            fflush(stdin);
            getline(cin, x[i].makhoa);
            cout << "Ten khoa: ";
            fflush(stdin);
            getline(cin, x[i].tenkhoa);
            cout << "Truong khoa: ";
            fflush(stdin);
            getline(cin, x[i].truongkhoa);
        }

        cout << "So ban: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cout << "Ban thu " << i + 1 << endl;
            cout << "Ma ban: ";
            fflush(stdin);
            getline(cin, y[i].maban);
            cout << "Ten ban: ";
            fflush(stdin);
            getline(cin, y[i].tenban);
            cout << "Ngay TL: ";
            fflush(stdin);
            getline(cin, y[i].ngaythanhlap);
        }
    }
    void xuat()
    {
        TRUONG::xuat();
        cout << "================== THONG TIN VE CAC KHOA ====================\n";
        cout << setw(10) << "Ma khoa" << setw(20) << "Ten khoa" << setw(15) << "Truong khoa" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << setw(10) << x[i].makhoa << setw(20) << x[i].tenkhoa << setw(20) << x[i].truongkhoa << endl;
        }
        cout << "=============================================================\n";

        cout << "================== THONG TIN VE CAC BAN =====================\n";
        cout << setw(10) << "Ma ban" << setw(20) << "Ten ban" << setw(15) << "Ngay thanh lap" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << setw(10) << y[i].maban << setw(20) << y[i].tenban << setw(12) << y[i].ngaythanhlap << endl;
        }
        cout << "=============================================================\n";
    }
    friend void xoa_Khoa(TRUONGDH a, int n);
};

void xoa_Khoa(TRUONGDH a)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i].makhoa == "KH01")
        {
            flag = true;
        }
    }
    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
    else
    {
        cout << "Khong ton tai ma khoa KH01\n";
    }
}

int main()
{
    TRUONGDH a;
    a.nhap();
    cout << "-------------------- THONG TIN VE TRUONG --------------------\n";
    a.xuat();
}