#include <bits/stdc++.h>
using namespace std;

class STUDENT;
class SCHOOL
{
private:
    string NAME, DATE;

public:
    friend class FACULTY;
    friend void suaTT(STUDENT &st, const string &newSchoolName);
};

class FACULTY
{
private:
    string Name;
    string date;
    SCHOOL x;

public:
    friend class STUDENT;
    void input()
    {
        cout << "Input school name: ";
        fflush(stdin);
        getline(cin, x.NAME);
        cout << "Input school date: ";
        fflush(stdin);
        getline(cin, x.DATE);
        cout << "Input faculty name: ";
        fflush(stdin);
        getline(cin, Name);
        cout << "Input faculty date: ";
        fflush(stdin);
        getline(cin, date);
    }

    void output()
    {
        cout << setw(15) << x.NAME << setw(15) << x.DATE << setw(15) << Name << setw(15) << date;
    }

    friend void suaTT(STUDENT &st, const string &newSchoolName);
};

class PERSON
{
protected:
    string name;
    string birth;
    string address;

public:
    void input()
    {
        cout << "Input name: ";
        fflush(stdin);
        getline(cin, name);
        cout << "Input birth: ";
        fflush(stdin);
        getline(cin, birth);
        cout << "Input address: ";
        fflush(stdin);
        getline(cin, address);
    }

    void output()
    {
        cout << setw(15) << name << setw(15) << birth << setw(20) << address;
    }

    PERSON()
    {
        name = "Van Duc";
        birth = "14/2/2002";
        address = "Da Nang";
    }
};

class STUDENT : public PERSON
{
private:
    FACULTY y;
    string Class;
    float score;

public:
    void input()
    {
        PERSON::input();
        y.input();
        cout << "Input class: ";
        fflush(stdin);
        getline(cin, Class);
        cout << "Input score: ";
        cin >> score;
    }

    void output()
    {
        PERSON::output();
        y.output();
        cout << setw(10) << Class << setw(10) << score << endl;
    }

    STUDENT() : PERSON()
    {
        Class = "KTPM";
        score = 7.9;
    }

    friend void suaTT(STUDENT &st, const string &newSchoolName);
};

void suaTT(STUDENT &st, const string &newSchoolName)
{
    st.y.x.NAME = newSchoolName;
}

int main()
{
    STUDENT s;
    s.input();
    cout << setw(15) << "Student Name" << setw(15) << "Birthday" << setw(20) << "Address" << setw(15) << "School Name" << setw(15) << "School Date" << setw(15) << "Faculty Name" << setw(15) << "Faculty Date" << setw(10) << "Class" << setw(10) << "Score" << endl;
    s.output();
    cout << "-------------------------- SAU KHI SUA TEN TRUONG ------------------------\n";
    cout << setw(15) << "Student Name" << setw(15) << "Birthday" << setw(20) << "Address" << setw(15) << "School Name" << setw(15) << "School Date" << setw(15) << "Faculty Name" << setw(15) << "Faculty Date" << setw(10) << "Class" << setw(10) << "Score" << endl;
    suaTT(s, "DHCNHN");
    s.output();
}