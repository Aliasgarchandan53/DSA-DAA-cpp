#include <iostream>
using namespace std;

int calcGCD(int n, int m){
    // Write your code here.
    int gcd=0; 
    int min = (m<n)?m:n;
    for(int i=min;i>=1;i--){
        if(((m%i)==0)&&((n%i)==0)){
            gcd=i;
            return gcd;
        }
    }
}

int main()
{
    int m,n;
    cin >> m>>n;
    int Gcd= calcGCD(m,n);
    cout << "gcd is " << Gcd << endl;
    return 0;
}

/*
for pattern :
12345
1234
123
....
for(int i=row;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }

Now, for 1,3,5,7,...

n=3:
__*
_***
*****
code:
for(int i=1;i<=row;i++){
        for(int j=(row-i);j>0;j--){
            cout<<" ";
        }
        for(int j=1;j<=(2*i -1);j++){
            cout<<"*";
        }
        cout<<endl;
    }

q3 :
1
01
101
0101
10101
        for(int j=1;j<=i;j++){
            if(((i%2!=0) && (j%2!=0)) || ((i%2==0) && (j%2==0)))
                cout<<"1 ";
            else
                cout<<"0 ";
        }

1    1
12  21
123321

for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }

        for(int j=2*(row-i);j>0;j--){
            cout<<" ";
        }

        for(int j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }

1
2 3
4 5 6
7 8 9 10

    for(int i=1;i<=row;i++){
        for(int j=1;j<=i;j++){
            cout<<(count++)<<" ";
        }
        cout<<endl;
    }

For capital letters, initialize the count wiyh ascii of "A" ie 65
    and for small letters with ascii as "97".

Frame :
****
*  *
*  *
****

n=2
222
212
222

*/