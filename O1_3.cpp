#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    int d, m, y;

public:
    friend class Phieu;
};

class NhanVien
{
private:
    string tenNV;
    string chucvu;
    string tenphong;
    string maphong;
    string truongphong;

public:
    friend class Phieu;
};

class TaiSan
{
private:
    string tents;
    int soluong;
    string tinhtrang;

public:
    void nhap()
    {
        cout << "Nhap ten ts: ";
        fflush(stdin);
        getline(cin, tents);
        cout << "Nhap so luong: ";
        cin >> soluong;
        cout << "Nhap tinh trang: ";
        fflush(stdin);
        getline(cin, tinhtrang);
    }
    void xuat()
    {
        cout << setw(20) << left << tents << "\t" << setw(10) << left << soluong << "\t" << setw(20) << left << tinhtrang << endl;
    }

    string getTenTS()
    {
        return tents;
    }

    int getQuantity()
    {
        return soluong;
    }

    void setQuantity(int soluong)
    {
        this->soluong = soluong;
    }
};

class Phieu
{
private:
    string maphieu;
    Date ngaykk;
    NhanVien nv;
    TaiSan *ts;
    int n;

public:
    void pnhap()
    {
        cout << "Nhap ma phieu: ";
        fflush(stdin);
        getline(cin, maphieu);
        cout << "Nhap ngay kiem ke: ";
        cin >> ngaykk.d >> ngaykk.m >> ngaykk.y;
        cout << "Nhap ten nhan vien: ";
        fflush(stdin);
        getline(cin, nv.tenNV);
        cout << "Nhap chuc vu: ";
        fflush(stdin);
        getline(cin, nv.chucvu);
        cout << "Nhap ten phong: ";
        fflush(stdin);
        getline(cin, nv.tenphong);
        cout << "Nhap ma phong: ";
        fflush(stdin);
        getline(cin, nv.maphong);
        cout << "Nhap truong phong: ";
        fflush(stdin);
        getline(cin, nv.truongphong);
        cout << "Nhap so luong tai san: ";
        cin >> n;
        cout << "Nhap thong tin tai san" << endl;
        ts = new TaiSan[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Tai san thu " << i + 1 << endl;
            ts[i].nhap();
        }
    }

    void pxuat()
    {
        cout << setw(20) << left << "Ma phieu: "
             << "\t" << setw(20) << left << maphieu << "\t" << setw(20) << left << "Ngay kiem ke: "
             << "\t" << ngaykk.d << "/" << ngaykk.m << "/" << ngaykk.y << endl;
        cout << setw(20) << left << "Nhan vien kiem ke: "
             << "\t" << setw(20) << left << nv.tenNV << "\t" << setw(20) << left << "Chuc vu: "
             << "\t" << setw(20) << left << nv.chucvu << endl;
        cout << setw(20) << left << "Kiem ke tai phong: "
             << "\t" << setw(20) << left << nv.tenphong << "\t" << setw(20) << left << "Ma phong: "
             << "\t" << setw(20) << left << nv.maphong << endl;
        cout << setw(20) << left << "Truong phong: " << nv.truongphong << endl;
        cout << endl;
        cout << setw(20) << left << "Ten tai san"
             << "\t" << setw(10) << left << "So luong"
             << "\t" << setw(20) << left << "Tinh trang" << endl;
        for (int i = 0; i < n; i++)
        {
            ts[i].xuat();
        }
        int d = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ts[i].getQuantity();
            d++;
        }
        cout << setw(20) << "So tai san da kiem ke: " << d << "\t" << setw(15) << "Tong so luong: " << sum << endl;
    }

    friend void suaSoLuong(Phieu &p);
    friend void sapxepSoLuongTang(Phieu &p);
};

// Sua thong tin So luong cua tai san "May vi tinh" (neu co) thanh 20.
void suaSoLuong(Phieu &p)
{
    for (int i = 0; i < p.n; i++)
    {
        if (p.ts[i].getTenTS() == "May vi tinh")
        {
            p.ts[i].setQuantity(20);
        }
    }
}

// Sap xep danh sach theo chieu tang so luong.
void sapxepSoLuongTang(Phieu &p)
{
    for (int i = 0; i < p.n - 1; i++)
    {
        for (int j = p.n - 1; j > i; j--)
        {
            if (p.ts[j].getQuantity() < p.ts[j - 1].getQuantity())
            {
                TaiSan tg = p.ts[j];
                p.ts[j] = p.ts[j - 1];
                p.ts[j - 1] = tg;
            }
        }
    }
}

int main()
{
    Phieu p;
    p.pnhap();
    cout << "------- PHIEU KIEM KE TAI SAN -------\n";
    p.pxuat();

    cout << "-------------- PHIEU SUA DOI SO LUONG MAY VI TINH BANG 20 ---------------\n";
    suaSoLuong(p);
    p.pxuat();

    cout << "-------------- SAP XEP TAI SAN KIEM KE THEO SO LUONG TANG ---------------\n";
    sapxepSoLuongTang(p);
    p.pxuat();
}