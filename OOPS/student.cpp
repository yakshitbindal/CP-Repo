#include<bits/stdc++.h>
using namespace std;
class Student
{
    int rollNumber;
    int age;
    

    public:
    static int totalStudents;
    //Default constructor
    Student()
    {
        cout<<"Constructor called"<<endl;
        //totalStudents++;
    }

    //Parameterized constructor
    Student(int rollNumber)
    {
        this->rollNumber=rollNumber;
    }

    Student(int rollNumber,int age)
    {
        this->rollNumber=rollNumber;
        this->age=age;
    }

    void display()
    {
        cout<<age<<" "<<rollNumber;
    }
    int getAge()
    {
        return age;
    }
    int getRollNumber()
    {
        return rollNumber;
    }
    void setAge(int a)
    {
        if(a<0)
        {
            return;
        }
        age=a; 
    }
    void setRollNumber(int rn)
    {
        rollNumber=rn;
    }
};

int Student :: totalStudents=0; //initialize static data members
