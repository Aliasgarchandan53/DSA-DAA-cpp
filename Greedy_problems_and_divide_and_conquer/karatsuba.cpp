#include <iostream>
#include <cmath>
using namespace std;

int karatsuba(int x,int y, int n,int base){
    if(n==1)
        return x*y;
    int m=n/2;
    int divisor=((int)pow(base,m));
    int x1,x0,y1,y0,p,q,r;
    x1=x/divisor;
    x0=x%divisor;
    y1=y/divisor;
    y0=y%divisor;

    p=karatsuba(x1,y1,m,base);
    q=karatsuba(x0,y0,m,base);
    r=karatsuba(x1-x0,y1-y0,m,base);

    return (p*((int)pow(base,(2*m))) +(p+q-r)*((int)pow(base,m)) +q);
}

int main(){
    int x,y,n,base;
    cout<<"Enter the base for multiplication :\n";
    cin>>base;
    cout<<"Enter number of digits n for multiplying n digit numbers :\n";
    cin>>n;
    cout<<"Enter two integers to multiply :\n";
    cin>>x>>y;
    int result= karatsuba(x,y,n,base);
    cout<<"The product is : "<<result<<endl;
}