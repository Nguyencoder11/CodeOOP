#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
    string nhanhieu, hang;
    int namsx;

public:
    void nhap()
    {
        cout << "Nhan hieu: ";
        fflush(stdin);
        getline(cin, nhanhieu);
        cout << "Nam san xuat: ";
        cin >> namsx;
        cout << "Hang: ";
        fflush(stdin);
        getline(cin, hang);
    }

    void xuat()
    {
        cout << setw(15) << nhanhieu << setw(12) << namsx << setw(15) << hang;
    }
};

class Oto : public Vehicle
{
private:
    int sochongoi;
    float dungtich;

public:
    void nhap()
    {
        Vehicle::nhap();
        cout << "So cho ngoi: ";
        cin >> sochongoi;
        cout << "Dung tich: ";
        cin >> dungtich;
    }

    void xuat()
    {
        Vehicle::xuat();
        cout << setw(12) << sochongoi << setw(12) << dungtich << endl;
    }

    friend void suaDungTich(Oto &a, const float &dt)
    {
        a.dungtich = dt;
    }
};

class Moto : public Vehicle
{
private:
    float phankhoi;

public:
    void nhap()
    {
        Vehicle::nhap();
        cout << "Phan khoi: ";
        cin >> phankhoi;
    }

    void xuat()
    {
        Vehicle::xuat();
        cout << setw(12) << phankhoi << endl;
    }
};

int main()
{
    Oto a;
    cout << "Nhap thong tin oto: \n";
    a.nhap();

    Moto b;
    cout << "Nhap thong tin moto: \n";
    b.nhap();

    cout << "------------------ THONG TIN VUA NHAP ------------------\n";
    cout << "O to: " << endl;
    cout << setw(15) << "Nhan hieu" << setw(12) << "Nam SX" << setw(15) << "Hang" << setw(12) << "So cho" << setw(12) << "Dung tich" << endl;
    a.xuat();
    cout << "Mo to: " << endl;
    cout << setw(15) << "Nhan hieu" << setw(12) << "Nam SX" << setw(15) << "Hang" << setw(12) << "Phan khoi" << endl;
    b.xuat();

    // Sua lai dung tich oto thanh 3.0
    cout << "------------------ THONG TIN O TO DA SUA ----------------\n";
    cout << setw(15) << "Nhan hieu" << setw(12) << "Nam SX" << setw(15) << "Hang" << setw(12) << "So cho" << setw(12) << "Dung tich" << endl;
    suaDungTich(a, 3.0);
    a.xuat();
}
