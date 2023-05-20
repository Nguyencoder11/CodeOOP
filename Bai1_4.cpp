#include <bits/stdc++.h>
using namespace std;

class SACH
{
    string bookID;
    string bookName;
    string NXB;
    int pageNumber;
    long money;

public:
    void input()
    {
        cout << "Nhap ma sach: ";
        fflush(stdin);
        getline(cin, bookID);
        cout << "Nhap ten sach: ";
        fflush(stdin);
        getline(cin, bookName);
        cout << "Nhap Nha xuat ban: ";
        fflush(stdin);
        getline(cin, NXB);
        cout << "Nhap so trang: ";
        cin >> pageNumber;
        cout << "Nhap gia sach: ";
        cin >> money;
    }

    void ouput()
    {
        cout << setw(10) << bookID << "\t" << setw(20) << bookName << "\t" << setw(20) << NXB << "\t" << setw(10) << pageNumber << "\t" << setw(15) << money << endl;
    }
};

int main()
{
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;
    SACH *a = new SACH[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Thong tin sach " << i + 1 << endl;
        a[i].input();
    }
    cout << "--- Thong tin ve cac sach da nhap ---" << endl;
    cout << setw(10) << "Ma sach"
         << "\t" << setw(20) << "Ten sach"
         << "\t" << setw(20) << "Nha xuat ban"
         << "\t" << setw(10) << "So trang"
         << "\t" << setw(15) << "Gia tien" << endl;

    for (int i = 0; i < n; i++)
    {
        a[i].ouput();
    }
}