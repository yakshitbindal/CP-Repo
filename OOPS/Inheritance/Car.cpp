#include<bits/stdc++.h>
using namespace std;
#include"Vehicle.cpp"
class Car : public Vehicle
{
    public:
    int numGears;

    void print()
    {
        cout<<"NumTyres: "<<numTyres<<endl;
        cout<<"Color: "<<color<<endl;
        cout<<"Num Gears: "<<numGears<<endl;
    }

};