#include <bits/stdc++.h>
using namespace std;


int MCM (vector<int>& a,vector<vector<int>>& brackets,int n){
    //initialising dp array;
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=1;i<n;i++)
        dp[i][i]=0;
    
    //calculating required multiplications.
    for(int l=2;l<n;l++){ //calculating chain lengths greater than 2
        for(int i=1;i<(n-l+1);i++){ //calculating possible starting points in each chain
            int j = (i+l-1); //calculating end point of a chain length l with startinng point i 
            dp[i][j]=INT_MAX;
            for(int k=i;k<=(j-1);k++){//iterating over all possible partitions of i and j
                int q = dp[i][k] + dp[k+1][j] + a[i-1]*a[j]*a[k]; //calculating multiplications for partition

                if(q<dp[i][j]){
                    dp[i][j]=q;
                    brackets[i][j]=k;
                }
            }
        }
    }
    return dp[1][n-1];
}

void printOptimalParenthization(int i,int j ,vector<vector<int>>& brackets,char& name){
    if(i==j){
        cout<<name++;
        return;
    }

    //recursively tracing bracket matrix to print the parenthization
    cout<<"(";
    printOptimalParenthization(i,brackets[i][j],brackets,name);
    printOptimalParenthization(brackets[i][j]+1,j,brackets,name);
    cout<<")";

}

void printOptimalOrder(vector<vector<int>>& brackets,int n){
    char name ='A';
    cout<<"The optimal parenthization of matrices is : \n";
    printOptimalParenthization(1,n,brackets,name);
}

int main(){

    int n; 
    cout<<"Enter the number of matrices to multiply : \n";
    cin>>n;
    vector<int> a(n+1);
    cout<<"Enter the dimensions of matrices (space separated) :\n";
    for(int i=0;i<=n;i++)
        cin>>a[i];

    vector<vector<int>> brackets(n+1,vector<int>(n+1));
    int multiplications=MCM(a,brackets,n+1);
    cout<<"Minimum number of multiplications required are : "<<multiplications<<endl;
    printOptimalOrder(brackets,n);
    return 0;
}