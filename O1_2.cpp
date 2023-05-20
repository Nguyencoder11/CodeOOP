#include <bits/stdc++.h>
using namespace std;

class Sinhvien
{
private:
    string masv, tensv, lop;
    int khoa;

public:
    friend class Phieu;
};

class Mon
{
private:
    string tenmon;
    int sotrinh;
    float diem;

public:
    friend class Phieu;
    void nhap()
    {
        cout << "Ten mon: ";
        fflush(stdin);
        getline(cin, tenmon);
        cout << "So trinh: ";
        cin >> sotrinh;
        cout << "Diem: ";
        cin >> diem;
    }

    void xuat()
    {
        cout << setw(25) << left << tenmon << setw(15) << sotrinh << setw(15) << diem << endl;
    }

    int getSotrinh()
    {
        return sotrinh;
    }

    int getDiemTong()
    {
        return sotrinh * diem;
    }
};

class Phieu
{
private:
    Sinhvien x;
    Mon *m;
    int n;

public:
    void nhap()
    {
        cout << "Nhap ma sv: ";
        fflush(stdin);
        getline(cin, x.masv);
        cout << "Ten sv: ";
        fflush(stdin);
        getline(cin, x.tensv);
        cout << "Lop: ";
        fflush(stdin);
        getline(cin, x.lop);
        cout << "Khoa: ";
        cin >> x.khoa;
        cout << "Nhap so mon hoc: ";
        cin >> n;
        m = new Mon[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Mon thu " << i + 1 << endl;
            m[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(12) << left << "Ma sinh vien: " << setw(10) << x.masv << setw(12) << "Ten sinh vien: " << x.tensv << endl;
        cout << setw(14) << left << "Lop: " << setw(10) << x.lop << setw(12) << "Khoa: " << x.khoa << endl;
        cout << "Bang diem: \n";

        cout << setw(25) << left << "Ten mon" << setw(15) << "So trinh" << setw(15) << "Diem" << endl;
        for (int i = 0; i < n; i++)
        {
            m[i].xuat();
        }

        float dtb = 0;
        int tongST = 0;
        for (int i = 0; i < n; i++)
        {
            dtb += m[i].getDiemTong();
            tongST += m[i].getSotrinh();
        }
        cout << right << setw(33) << "Diem trung binh";
        cout << setw(10) << setprecision(3) << dtb / tongST << endl;
    }

    // In cac mon hoc co so trinh >> 3
    void monHocSoTrinhTren3()
    {
        cout << "\n--- Danh sach cac mon hoc co so trinh > 3 ---\n";
        cout << setw(25) << left << "Ten mon" << setw(15) << "So trinh" << setw(15) << "Diem" << endl;
        for (int i = 0; i < n; i++)
        {
            if (m[i].getSotrinh() > 3)
            {
                m[i].xuat();
            }
        }
    }

    // Chen them mot mon hoc vao danh sach
    friend void chenMonHocMoi(Phieu &a);
};

void chenMonHocMoi(Phieu &a)
{
    int pos;
    cout << "Nhap vi tri can bo sung: ";
    cin >> pos;
    cout << "Nhap thong tin mon hoc can bo sung\n";
    Mon x;
    x.nhap();
    if (pos < 0 || pos > a.n)
    {
        cout << "Vi tri khong thich hop de chen\n";
    }
    else
    {
        for (int i = a.n - 1; i > pos - 1; i--)
        {
            a.m[i] = a.m[i - 1];
        }
        a.m[pos - 1] = x;
        ++a.n;
        cout << setw(25) << left << "Ten mon" << setw(15) << "So trinh" << setw(15) << "Diem" << endl;
        for (int i = 0; i < a.n; i++)
        {
            a.m[i].xuat();
        }
    }
}

int main()
{
    Phieu a;
    a.nhap();
    cout << "------------------ PHIEU BAO DIEM ------------------\n";
    a.xuat();
    a.monHocSoTrinhTren3();
    chenMonHocMoi(a);
}
