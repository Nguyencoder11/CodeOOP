#include <bits/stdc++.h>
using namespace std;

class DotPrinter;
class LaserPrinter;
class Printer
{
protected:
    float trongluong;
    string hangsx;
    int namsx;
    int tocdo;

public:
    friend void suaNamSx(DotPrinter &dp, const int &newYear);
    friend void suaNamSX(LaserPrinter &lp, const int &newYear);
};

class DotPrinter : public Printer
{
private:
    int matdokim;

public:
    void nhap()
    {
        cout << "Nhap trong luong: ";
        cin >> trongluong;
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, hangsx);
        cout << "Nhap nam sx: ";
        cin >> namsx;
        cout << "Nhap toc do: ";
        cin >> tocdo;
        cout << "Nhap mat do kim: ";
        cin >> matdokim;
    }

    void xuat()
    {
        cout << setw(15) << trongluong << "\t" << setw(20) << left << hangsx << "\t" << setw(10) << namsx << "\t" << setw(10) << tocdo << "\t" << setw(20) << matdokim << endl;
    }

    friend void suaNamSx(DotPrinter &dp, const int &newYear);
};

class LaserPrinter : public Printer
{
private:
    float dophangiai;

public:
    void nhap()
    {
        cout << "Nhap trong luong: ";
        cin >> trongluong;
        cout << "Nhap ten hang: ";
        fflush(stdin);
        getline(cin, hangsx);
        cout << "Nhap nam sx: ";
        cin >> namsx;
        cout << "Nhap toc do: ";
        cin >> tocdo;
        cout << "Nhap do phan giai: ";
        cin >> dophangiai;
    }

    void xuat()
    {
        cout << setw(15) << trongluong << "\t" << setw(20) << left << hangsx << "\t" << setw(10) << namsx << "\t" << setw(10) << tocdo << "\t" << setw(20) << dophangiai << endl;
    }

    friend void suaNamSX(LaserPrinter &lp, const int &newYear);
};

void suaNamSx(DotPrinter &dp, const int &newYear)
{
    dp.namsx = newYear;
}

void suaNamSX(LaserPrinter &lp, const int &newYear)
{
    lp.namsx = newYear;
}

int main()
{
    DotPrinter a;
    cout << "Nhap thong tin may in kim\n";
    a.nhap();

    LaserPrinter b;
    cout << "Nhap thon tin may in laser\n";
    b.nhap();

    cout << "===== THONG TIN MAY IN KIM =====" << endl;
    cout << setw(15) << left << "Trong luong"
         << "\t" << setw(20) << left << "Hang SX"
         << "\t" << setw(10) << "Nam SX"
         << "\t" << setw(10) << "Toc do"
         << "\t" << setw(20) << "Mat do kim" << endl;
    a.xuat();

    cout << "===== THONG TIN MAY IN LASER =====" << endl;
    cout << setw(15) << left << "Trong luong"
         << "\t" << setw(20) << left << "Hang SX"
         << "\t" << setw(10) << "Nam SX"
         << "\t" << setw(10) << "Toc do"
         << "\t" << setw(20) << "Do phan giai" << endl;
    b.xuat();

    // Sua lai nam cac may in
    cout << "\n============ THONG TIN CAC HANG SAU KHI SUA NAM SX ===============\n";
    cout << "------------- MAY IN KIM ------------\n";
    cout << setw(15) << left << "Trong luong"
         << "\t" << setw(20) << left << "Hang SX"
         << "\t" << setw(10) << "Nam SX"
         << "\t" << setw(10) << "Toc do"
         << "\t" << setw(20) << "Mat do kim" << endl;
    suaNamSx(a, 2020);
    a.xuat();

    cout << "------------ MAY IN LASER -----------\n";
    cout << setw(15) << left << "Trong luong"
         << "\t" << setw(20) << left << "Hang SX"
         << "\t" << setw(10) << "Nam SX"
         << "\t" << setw(10) << "Toc do"
         << "\t" << setw(20) << "Do phan giai" << endl;
    suaNamSX(b, 2020);
    b.xuat();
}