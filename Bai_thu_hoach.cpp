#include <bits/stdc++.h>
using namespace std;

class HANG
{
private:
    string MAH, TENH;
    int DG, SL, NAM;

public:
    HANG()
    {
        MAH = "H001";
        TENH = "Tivi";
        DG = 300;
        SL = 3;
        NAM = 2018;
    }

    HANG(string MAH, string TENH, int DG, int SL, int NAM)
    {
        this->MAH = MAH;
        this->TENH = TENH;
        this->DG = DG;
        this->SL = SL;
        this->NAM = NAM;
    }

    string getMaH()
    {
        return MAH;
    }

    int getDonGia()
    {
        return DG;
    }

    friend istream &operator>>(istream &is, HANG &y)
    {
        cout << "Nhap ma hang: ";
        fflush(stdin);
        getline(cin, y.MAH);
        cout << "Ten hang: ";
        fflush(stdin);
        getline(cin, y.TENH);
        cout << "Don gia: ";
        is >> y.DG;
        cout << "So luong: ";
        is >> y.SL;
        cout << "Nam sx: ";
        is >> y.NAM;
        return is;
    }

    friend ostream &operator<<(ostream &os, HANG &y)
    {
        os << setw(12) << y.MAH << setw(20) << y.TENH << setw(15) << y.DG << setw(15) << y.SL << setw(12) << y.NAM << setw(15) << y.DG * y.SL << endl;
        return os;
    }

    // kiem tra xem danh sach co mat hang "IPHONE 12" khong.
    friend void checkIphone12(HANG *h, int n)
    {
        bool checked = false;
        for (int i = 0; i < n; i++)
        {
            if (h[i].TENH == "IPHONE 12")
            {
                checked = true;
            }
        }

        if (!checked)
        {
            cout << "Danh sach da nhap khong co mat hang IPHONE 12\n";
        }
        else
        {
            cout << "Da tim thay mat hang IPHONE 12 trong danh sach\n";
        }
    }

    // sap xep danh sach theo chieu tang thanh tien.
    friend void sapxepThanhTien(HANG *h, int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (h[j].DG * h[j].SL < h[j - 1].DG * h[j - 1].SL)
                {
                    HANG tg = h[j];
                    h[j] = h[j - 1];
                    h[j - 1] = tg;
                }
            }
        }
    }

    // Xoa mat hang co ma H005 khoi danh sach.
    friend int removeMaH(HANG *h, int n);

    // Xoa moi mat hang co don gia nho hon 20.
    friend int removeHang(HANG *h, int n);
};

int removeMaH(HANG *h, int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i].MAH == "H005")
        {
            flag = 1;
        }
    }
    return flag;
}

int removeHang(HANG *h, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i].DG < 20)
        {
            dem++;
        }
    }
    return dem;
}

int main()
{
    int n;
    HANG *h;
    do
    {
        cout << "Nhap so luong hang: ";
        cin >> n;
    } while (n <= 0);
    h = new HANG[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Hang thu " << i + 1 << endl;
        cin >> h[i];
    }

    // In danh sach da nhap
    cout << "------------------------------------- DANH SACH VUA NHAP -------------------------------------\n";
    cout << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << h[i];
    }
    cout << "----------------------------------------------------------------------------------------------\n";
    ofstream f("HANGNHAP.dat", ios::out);
    f << "------------------------------------- DANH SACH VUA NHAP -------------------------------------\n";
    f << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
    for (int i = 0; i < n; i++)
    {
        f << h[i];
    }
    f << "----------------------------------------------------------------------------------------------\n";
    f.close();

    // Kiem tra mat hang IPHONE 12
    checkIphone12(h, n);

    // sap xep danh sach theo chieu tang thanh tien.
    ofstream file("HANGSORT.txt", ios::out);
    cout << "------------------------------------ DANH SACH DA SAP XEP ------------------------------------\n";
    file << "------------------------------------ DANH SACH DA SAP XEP ------------------------------------\n";
    sapxepThanhTien(h, n);
    cout << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
    file << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << h[i];
        file << h[i];
    }
    cout << "----------------------------------------------------------------------------------------------\n";
    file << "----------------------------------------------------------------------------------------------\n";
    file.close();

    // Xoa hang co ma H005 ra khoi danh sach
    ofstream fi("HANGREMOVE.txt", ios::out);
    if (removeMaH(h, n) == 0)
    {
        cout << "Khong ton tai hang co ma H005\n";
        cout << "Khong tim thay du lieu de xoa\n";
        fi << "Khong ton tai hang co ma H005\n";
        fi << "Khong tim thay du lieu de xoa\n";
    }
    else
    {
        cout << "----------------------------- DANH SACH DA XOA HANG CO MA H005 -------------------------------\n";
        fi << "----------------------------- DANH SACH DA XOA HANG CO MA H005 -------------------------------\n";
        for (int i = 0; i < n; i++)
        {
            if (h[i].getMaH() == "H005")
            {
                for (int k = i; k < n - 1; k++)
                {
                    h[k] = h[k + 1];
                }
                n--;
                i--; // Giam i de kiem tra lai phan tu sau khi dich
            }
        }
        cout << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
        fi << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << h[i];
            fi << h[i];
        }
        cout << "----------------------------------------------------------------------------------------------\n";
        fi << "----------------------------------------------------------------------------------------------\n";
    }
    fi.close();

    // Xoa cac mat hang co don gia < 20
    ofstream f3;
    f3.open("HANGREMOVE.txt", ios::app);
    if (removeHang(h, n) == 0)
    {
        cout << "Khong co mat hang nao co don gia < 20\n";
        cout << "Khong co du lieu de xoa\n";
        f3 << "Khong co mat hang nao co don gia < 20\n";
        f3 << "Khong co du lieu de xoa\n";
    }
    else
    {
        cout << "-------------------------- DANH SACH DA XOA HANG CO DON GIA DUOI 20 --------------------------\n";
        f3 << "-------------------------- DANH SACH DA XOA HANG CO DON GIA DUOI 20 --------------------------\n";
        for (int i = 0; i < n; i++)
        {
            if (h[i].getDonGia() < 20)
            {
                for (int k = i; k < n - 1; k++)
                {
                    h[k] = h[k + 1];
                }
                n--;
                i--; // Giam i de kiem tra lai phan tu sau khi dich
            }
        }
        cout << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
        f3 << setw(12) << "Ma hang" << setw(20) << "Ten hang" << setw(15) << "Don gia" << setw(15) << "So luong" << setw(12) << "Nam SX" << setw(15) << "Thanh tien" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << h[i];
            f3 << h[i];
        }
        cout << "----------------------------------------------------------------------------------------------\n";
        f3 << "----------------------------------------------------------------------------------------------\n";
    }
    f3.close();
}