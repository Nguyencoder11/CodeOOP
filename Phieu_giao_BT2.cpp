#include <bits/stdc++.h>
using namespace std;

class CLASS;
class PERSON
{
protected:
    string fullName, birthDay, homeTown;

public:
    void input()
    {
        cout << "Full name: ";
        fflush(stdin);
        getline(cin, fullName);
        cout << "Birthday: ";
        fflush(stdin);
        getline(cin, birthDay);
        cout << "Home town: ";
        fflush(stdin);
        getline(cin, homeTown);
    }
    void output()
    {
        cout << setw(20) << fullName << setw(12) << birthDay << setw(20) << homeTown;
    }
};

class STUDENT : public PERSON
{
private:
    string studentID, major;
    int course;

public:
    friend class CLASS;
    void input()
    {
        cout << "Input studentID: ";
        fflush(stdin);
        getline(cin, studentID);
        PERSON::input();
        cout << "Major: ";
        fflush(stdin);
        getline(cin, major);
        cout << "Course: ";
        cin >> course;
    }

    void output()
    {
        cout << setw(15) << studentID;
        PERSON::output();
        cout << setw(20) << major << setw(12) << course << endl;
    }

    friend void studentCourse11(CLASS &a);
};

class CLASS
{
private:
    string classID, className, openDate;
    STUDENT *x;
    int n;
    string teacherName;

public:
    void input()
    {
        cout << "Input classID: ";
        fflush(stdin);
        getline(cin, classID);
        cout << "Class name: ";
        fflush(stdin);
        getline(cin, className);
        cout << "Opened day: ";
        fflush(stdin);
        getline(cin, openDate);
        cout << "Teacher: ";
        fflush(stdin);
        getline(cin, teacherName);
        do
        {
            cout << "A number of students: ";
            cin >> n;
        } while (n <= 0);
        x = new STUDENT[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << endl;
            x[i].input();
        }
    }

    void output()
    {
        cout << setw(15) << left << "Class ID: " << classID << endl;
        cout << setw(20) << left << "Class name: " << className << endl;
        cout << setw(15) << left << "Opened day: " << openDate << endl;
        cout << setw(20) << left << "Teacher: " << teacherName << endl;
        cout << "===================================== CLASS INFORMATION =====================================\n";
        cout << setw(15) << "Student ID" << setw(20) << "Full name" << setw(12) << "Birthday" << setw(20) << "Home town" << setw(20) << "Major" << setw(12) << "Course" << endl;
        for (int i = 0; i < n; i++)
        {
            x[i].output();
        }
    }

    friend void studentCourse11(CLASS &a);
};

void studentCourse11(CLASS &a)
{
    int count = 0;
    for (int i = 0; i < a.n; i++)
    {
        if (a.x[i].course == 11)
        {
            count++;
        }
    }
    if (count)
    {
        cout << "The number of students study in course 11: " << count << endl;
    }
    else
        cout << "Not have students study in course 11\n";
}

int main()
{
    CLASS myclass;
    myclass.input();
    myclass.output();
    studentCourse11(myclass);
}