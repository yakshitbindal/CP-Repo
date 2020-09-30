#include<bits/stdc++.h>
using namespace std;
#include"Fraction.cpp"
int main()
{
    Fraction f1(10,2);
    Fraction f2(15,4);
    
    Fraction const f3; //with constant objects we can call only constant functions

    cout<<f3.getNumerator()<<" "<<f3.getDenominator()<<endl;

    //constant functions: which doesn't change any property of current object
    

}