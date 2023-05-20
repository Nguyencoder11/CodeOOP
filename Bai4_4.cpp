#include <bits/stdc++.h>
using namespace std;

class Electronic
{
protected:
    float congsuat, dienap;

public:
    Electronic(float congsuat, float dienap)
    {
        this->congsuat = congsuat;
        this->dienap = dienap;
    }
};

class Maygiat : public Electronic
{
private:
    float dungTich;
    string loai;

public:
    Maygiat(float congsuat, float dienap, float dungTich, string loai) : Electronic(congsuat, dienap)
    {
        this->dungTich = dungTich;
        this->loai = loai;
    }

    void xuat()
    {
        cout << setw(12) << congsuat << setw(12) << dienap << setw(12) << dungTich << setw(15) << loai << endl;
    }
};

class Tulanh : public Electronic
{
private:
    float dungtich;
    int songan;

public:
    Tulanh(float congsuat, float dienap, float dungtich, int songan) : Electronic(congsuat, dienap)
    {
        this->dungtich = dungtich;
        this->songan = songan;
    }

    void xuat()
    {
        cout << setw(12) << congsuat << setw(12) << dienap << setw(12) << dungtich << setw(15) << songan << endl;
    }
};

int main()
{
    Maygiat a(120, 220, 2, "Toshiba");
    Tulanh b(150, 220, 1.5, 3);
    cout << "----------------------- MAY GIAT ------------------------\n";
    cout << setw(12) << "Cong suat" << setw(12) << "Dien ap" << setw(12) << "Dung tich" << setw(15) << "Loai" << endl;
    a.xuat();

    cout << "----------------------- TU LANH -------------------------\n";
    cout << setw(12) << "Cong suat" << setw(12) << "Dien ap" << setw(12) << "Dung tich" << setw(15) << "So ngan" << endl;
    b.xuat();
}