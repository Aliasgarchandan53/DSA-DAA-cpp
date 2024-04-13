#include <bits/stdc++.h>
using namespace std;

int Karatsuba(int x,int y,int n){
    if(n==1){
        cout<<"x,y,xy = "<<x<<" "<<y<<" "<<(x*y)<<endl;
        return x*y;}
    int m = n/2;
    int div = pow(10,m);
    int x1 = x/div;
    int x0 = x%div;
    int y1 = y/div;
    int y0 = y%div;
    cout<<"The values of m,div,x1,y1,x0,y0 are : "<<m<<" "<<div<<" "<<x1<<" "<<y1<<" "<<x0<<" "<<y0<<endl;
    int p = Karatsuba(x1,y1,m);
    int q = Karatsuba(x0,y0,m);
    int r = Karatsuba(x1-x0,y1-y0,m);

    cout<<"The values of p,q,r are :"<<p<<" "<<q<<" "<<r<<" "<<endl;

    return (p*pow(10,2*m)+(p+q-r)*pow(10,m)+q);
}


int main(){
    int n,x,y;
    cout<<"Enter max no of digits :\n";
    cin>>n;
    cout<<"Enter two integers : ";
    cin>>x>>y;
    int result = Karatsuba(x,y,n);
    cout<<"The product is "<<result<<endl;
    return 0;
}