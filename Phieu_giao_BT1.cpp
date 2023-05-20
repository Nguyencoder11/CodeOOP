#include <bits/stdc++.h>
using namespace std;

class Phieu;
class Ncc
{
private:
    string mancc, tenncc, diachi, sdt;

public:
    friend class Phieu;
};

class Sanpham
{
private:
    string masp, tensp;
    int soluong, dongia;

public:
    void nhap()
    {
        cout << "Ma SP: ";
        fflush(stdin);
        getline(cin, masp);
        cout << "Ten SP: ";
        fflush(stdin);
        getline(cin, tensp);
        cout << "So luong: ";
        cin >> soluong;
        cout << "Don gia: ";
        cin >> dongia;
    }

    void xuat()
    {
        cout << setw(20) << masp << setw(20) << tensp << setw(15) << soluong << setw(15) << dongia << setw(15) << soluong * dongia << endl;
    }

    int getTien()
    {
        return soluong * dongia;
    }

    friend void soLuongDuoi80(Phieu &a);
    friend void sapXepDonGiaTang(Phieu &a);
};

class Phieu
{
private:
    string maphieu;
    string ngaylap;
    Ncc x;
    Sanpham *sp;
    int n;

public:
    void nhap()
    {
        cout << "Nhap ma phieu: ";
        fflush(stdin);
        getline(cin, maphieu);
        cout << "Ngay lap: ";
        fflush(stdin);
        getline(cin, ngaylap);
        cout << "Ma NCC: ";
        fflush(stdin);
        getline(cin, x.mancc);
        cout << "Ten NCC: ";
        fflush(stdin);
        getline(cin, x.tenncc);
        cout << "Dia chi: ";
        fflush(stdin);
        getline(cin, x.diachi);
        cout << "SoDT: ";
        fflush(stdin);
        getline(cin, x.sdt);
        cout << "So luong san pham: ";
        cin >> n;
        sp = new Sanpham[n];
        for (int i = 0; i < n; i++)
        {
            cout << "San pham " << i + 1 << endl;
            sp[i].nhap();
        }
    }
    void xuat()
    {
        cout << setw(10) << left << "Ma phieu: " << setw(20) << maphieu << "\t" << setw(15) << left << "Ngay lap: " << setw(15) << ngaylap << endl;
        cout << setw(20) << left << "Ma nha cung cap: " << setw(10) << x.mancc << "\t" << setw(20) << left << "Ten nha cung cap: " << setw(20) << x.tenncc << endl;
        cout << setw(8) << left << "Dia chi: " << setw(22) << x.diachi << "\t" << setw(10) << left << "SDT: " << setw(15) << x.sdt << endl;
        cout << "---------------------------------------------------------------------------------\n";
        cout << setw(20) << "Ma san pham" << setw(20) << "Ten san pham" << setw(15) << "So luong" << setw(15) << "Don gia" << setw(15) << "Thanh tien" << endl;
        cout << "---------------------------------------------------------------------------------\n";
        for (int i = 0; i < n; i++)
        {
            sp[i].xuat();
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += sp[i].getTien();
        }
        cout << "\t\t\t\t TONG \t\t\t\t\t" << sum << endl;

        cout << "---------------------------------------------------------------------------------\n";
        cout << endl;
        cout << setw(35) << "Hieu truong" << setw(35) << "Phong tai chinh" << setw(35) << "Nguoi lap" << endl;
    }

    // Dem so luong san pham < 80
    friend void soLuongDuoi80(Phieu &a);

    // Sap xep danh sach cac san pham theo chieu tang dan don gia va in lai
    friend void sapXepDonGiaTang(Phieu &a);
};

void soLuongDuoi80(Phieu &a)
{
    int dem = 0;
    for (int i = 0; i < a.n; i++)
    {
        if (a.sp[i].soluong < 80)
        {
            dem++;
        }
    }
    if (dem)
    {
        cout << "So luong san pham co so luong nhap nho hon 80: " << dem << endl;
    }
    else
    {
        cout << "Khong co san pham nao co so luong nhap nho hon 80\n";
    }
}

void sapXepDonGiaTang(Phieu &a)
{
    for (int i = 0; i < a.n - 1; i++)
    {
        for (int j = a.n - 1; j > i; j--)
        {
            if (a.sp[j].dongia < a.sp[j - 1].dongia)
            {
                Sanpham tg = a.sp[j];
                a.sp[j] = a.sp[j - 1];
                a.sp[j - 1] = tg;
            }
        }
    }
}

int main()
{
    Phieu a;
    a.nhap();
    cout << "=================================================================================\n";
    cout << setw(15) << left << "Dai hoc Victorya\n";
    cout << "\t\t\t PHIEU NHAP VAN PHONG PHAM \n";
    a.xuat();
    cout << "=================================================================================\n";
    soLuongDuoi80(a);
    // In lai phieu
    cout << "=================================================================================\n";
    cout << setw(15) << left << "Dai hoc Victorya\n";
    cout << "\t\t\t PHIEU NHAP VAN PHONG PHAM \n";
    sapXepDonGiaTang(a);
    a.xuat();
    cout << "=================================================================================\n";
    /*------- Copyright by Nguyencoder11 -------*/
}
