#include<bits/stdc++.h>
using namespace std;
class Fraction
{
    private:
    int numerator,denominator;
    
    public:

    Fraction()
    {

    }

    Fraction(int numerator,int denominator)
    {
        this->numerator=numerator;
        this->denominator=denominator;
    }

    int getNumerator() const
    {
        return numerator;
    }
    
    int getDenominator() const
    {
        return denominator;
    }
    
    void setNumerator(int n)
    {
        numerator=n;
    }
    
    void setDenominator(int d)
    {
        denominator=d;
    }

    void print()
    {
        cout<<numerator<<"/"<<denominator<<endl;
    }
    
    void simplify()
    {
        int gcd=1;
        int j=min(numerator,denominator);
        for(int i=1;i<=j;i++)
        {
            if(numerator%i==0 && denominator%i==0)
                gcd=i;
        }
        numerator/=gcd;
        denominator/=gcd;
    }

    void add(Fraction const &f2)
    {
        int lcm=denominator*f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;
        int num=(x*numerator)+(y*f2.numerator);
        numerator=num;
        denominator=lcm;
        simplify();
    }

    void multiply(Fraction const &f2)
    {
        numerator=numerator*f2.numerator;
        denominator=denominator*f2.denominator;
        simplify();
    }
};