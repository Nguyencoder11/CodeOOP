#include <bits/stdc++.h>
using namespace std;

class Nsx
{
    char maNCC[10];
    string tenNCC;
    string diaChi;

public:
    friend class Phieu;
    void nhap()
    {
        cout << "Nhap ma NCC: ";
        fflush(stdin);
        gets(maNCC);
        cout << "Nhap ten NCC: ";
        fflush(stdin);
        getline(cin, tenNCC);
        cout << "Nhap dia chi NCC: ";
        fflush(stdin);
        getline(cin, diaChi);
    }

    void xuat()
    {
        cout << setw(10) << left << "Ma NCC: " << setw(10) << left << maNCC << "\t" << setw(10) << left << "Ten NCC: " << setw(30) << tenNCC << endl;
        cout << setw(10) << left << "Dia chi: " << setw(50) << diaChi << endl;
    }
};

class Date
{
    int d, m, y;

public:
    friend class Phieu;
    void nhap()
    {
        cout << "Ngay nhap: ";
        cin >> d >> m >> y;
    }

    void xuat()
    {
        cout << d << "/" << m << "/" << y;
    }
};

class Hang
{
    string tenHang;
    float donGia;
    int soLuong;

public:
    friend class Phieu;
    void nhap()
    {
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, tenHang);
        cout << "Nhap don gia: ";
        cin >> donGia;
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }
    
    void xuat()
    {
        cout << setw(10) << tenHang << "\t" << setw(10) << donGia << "\t" << setw(10) << soLuong << "\t" << setw(10) << soLuong * donGia << endl;
    }

    float getMoney()
    {
        return donGia * soLuong;
    }
};

class Phieu
{
private:
    char maPhieu[10];
    Nsx nsx;
    Date nn;
    Hang *h;
    int n;

public:
    void nhap()
    {
        cout << "Nhap ma phieu: ";
        fflush(stdin);
        gets(maPhieu);
        nn.nhap();
        nsx.nhap();
        cout << "Nhap so luong hang: ";
        cin >> n;
        h = new Hang[n];
        cout << "==>Nhap thong tin cac mat hang\n";
        for (int i = 0; i < n; i++)
        {
            h[i].nhap();
        }
    }

    void xuat()
    {
        cout << setw(10) << left << "Ma phieu: " << setw(10) << left << maPhieu << "\t"
             << setw(10) << left << "Ngay lap: ";
        nn.xuat();
        cout << endl;
        nsx.xuat();
        cout << setw(10) << "Ten hang"
             << "\t" << setw(10) << "Don gia"
             << "\t" << setw(10) << "So luong"
             << "\t" << setw(10) << "Thanh tien" << endl;
        for (int i = 0; i < n; i++)
        {
            h[i].xuat();
        }
        float tong = 0;
        for (int i = 0; i < n; i++)
        {
            tong += h[i].getMoney();
        }
        cout << setw(40) << right << "Cong thanh tien"
             << "\t" << setw(10) << left << tong << endl;
    }
};

int main()
{
    Phieu p;
    p.nhap();
    cout << "========= THONG TIN PHIEU NHAP HANG =========\n";
    p.xuat();
}
