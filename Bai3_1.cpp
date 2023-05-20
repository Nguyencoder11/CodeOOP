#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
private:
    char masv[10];
    string hoten;
    float diemToan, diemLy, diemHoa;

public:
    void nhap()
    {
        cout << "Nhap ma sv: ";
        fflush(stdin);
        gets(masv);
        cout << "Nhap ho ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout << "Nhap diem Toan, Ly, Hoa: ";
        cin >> diemToan >> diemLy >> diemHoa;
    }

    void xuat()
    {
        cout << setw(10) << masv << "\t" << setw(20) << hoten << "\t" << setw(10) << diemToan << "\t" << setw(10) << diemLy << "\t" << setw(10) << diemHoa << "\t" << setw(10) << diemtong() << endl;
    }

    float diemtong()
    {
        return diemToan + diemLy + diemHoa;
    }

    friend void sapxep_tongdiem(SinhVien a[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (a[j].diemtong() < a[j - 1].diemtong())
                {
                    SinhVien tg = a[j];
                    a[j] = a[j - 1];
                    a[j - 1] = tg;
                }
            }
        }
    }
};

int main()
{
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    SinhVien *a = new SinhVien[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Sinh vien " << i + 1 << endl;
        a[i].nhap();
    }
    cout << ">>--- Thong tin sinh vien ---<<" << endl;
    cout << setw(10) << "Ma SV"
         << "\t" << setw(20) << "Ho Ten"
         << "\t" << setw(10) << "Diem Toan"
         << "\t" << setw(10) << "Diem Ly"
         << "\t" << setw(10) << "Diem Hoa"
         << "\t" << setw(10) << "Tong diem" << endl;
    sapxep_tongdiem(a, n);
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}