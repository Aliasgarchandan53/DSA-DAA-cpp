//Karatsuba 

#include <bits/stdc++.h>
using namespace std;

int Karatsuba(int x , int y,int n){
    if(n==1)
        return x*y;
    int m =n/2;
    int div = static_cast<int>(pow(10,m));
    int x1 = x/div;
    int x0 = x%div;
    int y1 = y/div;
    int y0 = y%div;

    int p = Karatsuba(x1,y1,m);
    int q = Karatsuba(x0,y0,m);
    int r =Karatsuba(x1-x0,y1-y0,m);

    return (p*pow(10,2*m)+(p+q-r)*pow(10,m)+q);
}

int main(){
    int x,y,n;
    cout<<"Enter the max size of integers :\n";
    cin>>n;
    cout<<"Enter two integers to multiply :\n";
    cin>>x>>y;
    int result = Karatsuba(x,y,n);
    cout<<"Product is : "<<result<<endl;
    return 0;
}