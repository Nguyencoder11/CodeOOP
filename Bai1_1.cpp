#include <bits/stdc++.h>
using namespace std;

class SINHVIEN
{
    char Masv[10];
    string Hoten;
    int Tuoi;
    float Diem;

public:
    void nhap()
    {
        cout << "Nhap ma sv: ";
        fflush(stdin);
        gets(Masv);
        cout << "Nhap ten sinh vien: ";
        fflush(stdin);
        getline(cin, Hoten);
        cout << "Nhap tuoi: ";
        cin >> Tuoi;
        cout << "Nhap diem: ";
        cin >> Diem;
    }

    void xuat()
    {
        cout << setw(10) << Masv << "\t" << setw(20) << Hoten << "\t" << setw(10) << Tuoi << "\t" << setw(5) << Diem << endl;
    }
};

int main()
{
    SINHVIEN a, b;
    cout << "--- Nhap thong tin sinh vien A ---" << endl;
    a.nhap();
    cout << "--- Nhap thong tin sinh vien B ---" << endl;
    b.nhap();
    cout << "--------------- Thong tin cac sinh vien ---------------" << endl;
    cout << setw(10) << "Ma SV"
         << "\t" << setw(20) << "Ho va ten"
         << "\t" << setw(10) << "Tuoi"
         << "\t" << setw(5) << "Diem" << endl;
    a.xuat();
    b.xuat();
}