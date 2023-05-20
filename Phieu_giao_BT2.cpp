#include <bits/stdc++.h>
using namespace std;

class PERSON
{
protected:
    string fullName, birthDay, homeTown;

public:
    void input() {}
    void output() {}
};

class STUDENT : public PERSON
{
private:
    string studentID, major;
    int course;
};

class CLASS
{
};

int main()
{
}