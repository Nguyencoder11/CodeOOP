#include <bits/stdc++.h>
using namespace std;

class BenhNhan;
class Nguoi
{
protected:
    string hoten;
    int tuoi;

public:
    friend class BenhVien;
    void nhap()
    {
        cout << "Ten benh nhan: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Tuoi: ";
        cin >> tuoi;
    }
    void xuat()
    {
        cout << setw(20) << hoten << setw(10) << tuoi;
    }

    friend int so_benhnhan_tren30(BenhNhan *bn, int n);
    friend void sua_tuoi(BenhNhan *bn, int n);
};

class BenhVien
{
private:
    string tenbenhvien;
    string diachi;
    string giamdoc;

public:
    friend class BenhNhan;
};

class BenhNhan : public Nguoi
{
private:
    string ma;
    string tiensu, chuandoan;
    BenhVien benhvien;

public:
    void nhap()
    {
        cout << "Nhap ma benh nhan: ";
        fflush(stdin);
        getline(cin, ma);
        Nguoi::nhap();
        cout << "Tien su: ";
        fflush(stdin);
        getline(cin, tiensu);
        cout << "Chuan doan: ";
        fflush(stdin);
        getline(cin, chuandoan);
        cout << "Ten benh vien: ";
        fflush(stdin);
        getline(cin, benhvien.tenbenhvien);
        cout << "Dia chi: ";
        fflush(stdin);
        getline(cin, benhvien.diachi);
        cout << "Giam doc: ";
        fflush(stdin);
        getline(cin, benhvien.giamdoc);
    }
    void xuat()
    {
        cout << setw(8) << ma;
        Nguoi::xuat();
        cout << setw(15) << tiensu << setw(20) << chuandoan << setw(20) << benhvien.tenbenhvien << setw(20) << benhvien.diachi << setw(20) << benhvien.giamdoc << endl;
    }

    friend int so_benhnhan_tren30(BenhNhan *bn, int n);
    friend void sua_tuoi(BenhNhan *bn, int n);
};

// In danh sach benh nhan tuoi lon hon 30
int so_benhnhan_tren30(BenhNhan *bn, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (bn[i].tuoi > 30)
        {
            dem++;
        }
    }
    return dem;
}

// Sua tuoi cua benh nhan ma "BN01" thanh 20
void sua_tuoi(BenhNhan *bn, int n)
{
    bool findOut = false;
    for (int i = 0; i < n; i++)
    {
        if (bn[i].ma == "BN01")
        {
            findOut = true;
        }
    }
    if (findOut)
    {
        for (int i = 0; i < n; i++)
        {
            if (bn[i].ma == "BN01")
            {
                bn[i].tuoi = 20;
            }
        }
        cout << setw(8) << "Ma BN" << setw(20) << "Ho ten" << setw(10) << "Tuoi" << setw(15) << "Tien su" << setw(20) << "Chuan doan" << setw(20) << "Ten benh vien" << setw(20) << "Dia chi" << setw(20) << "Giam doc" << endl;
        for (int i = 0; i < n; i++)
        {
            bn[i].xuat();
        }
    }
    else
    {
        cout << "Khong tim thay benh nhan co ma BN01\n";
    }
}

int main()
{
    int n;
    BenhNhan *bn;
    do
    {
        cout << "So luong benh nhan: ";
        cin >> n;
    } while (n <= 0);
    bn = new BenhNhan[n];
    cout << "-----> Nhap thong tin cac benh nhan\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Benh nhan " << i + 1 << endl;
        bn[i].nhap();
    }

    cout << "====================================================== THONG TIN DANH SACH BENH NHAN ===================================================================\n";
    cout << setw(8) << "Ma BN" << setw(20) << "Ho ten" << setw(10) << "Tuoi" << setw(15) << "Tien su" << setw(20) << "Chuan doan" << setw(20) << "Ten benh vien" << setw(20) << "Dia chi" << setw(20) << "Giam doc" << endl;
    for (int i = 0; i < n; i++)
    {
        bn[i].xuat();
    }
    cout << "========================================================================================================================================================\n";

    if (so_benhnhan_tren30(bn, n))
    {
        cout << "So benh nhan co tuoi lon hon 30 la " << so_benhnhan_tren30(bn, n) << endl;
    }
    else
    {
        cout << "Khong co benh nhan nao lon hon 30 tuoi\n";
    }
    cout << "===================================================== DANH SACH SAU KHI SUA TUOI BN01 ==================================================================\n";
    sua_tuoi(bn, n);
    cout << "========================================================================================================================================================\n";
}