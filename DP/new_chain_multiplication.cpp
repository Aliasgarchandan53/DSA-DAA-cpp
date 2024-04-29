/*Matrix Chain Multiplication - chain mult function, printOptimalOrder, main */

#include <bits/stdc++.h>
using namespace std;


void printOptimalOrder(int i,int j ,vector<vector<int>> &brackets,char &name){
    //base case
    if(i==j){
        cout<<(name++);
        return;
    }
    cout<<"(";
    printOptimalOrder(i,brackets[i][j],brackets,name);
    printOptimalOrder(brackets[i][j]+1,j,brackets,name);
    cout<<")";
}

void MCM(vector<int> &dim,int n){
    //initialising dp array 
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    vector<vector<int>> brackets(n+1,vector<int>(n+1));
    for(int i=1;i<n;i++)
        dp[i][i]=0;

    //mcm algorithm
    for(int l=2;l<=n;l++){ // chains of length L>=2
        for(int i=1;i<=(n-l+1);i++){ //finding starting point of each chain
            int j = (i+l-1); //end point of chain
            dp[i][j]=INT_MAX;
            for(int k = i;k<j;k++){
                int product = dp[i][k] + dp[k+1][j] + dim[i-1]*dim[j]*dim[k];
                if(product<dp[i][j]){
                    dp[i][j]=product;
                    brackets[i][j]=k;
                }
            }
        }
    }
    cout<<"Minimum number of multiplications needed to multiply the matrices are "<<dp[1][n-1]<<endl;
    char name ='A';
    printOptimalOrder(1,n-1,brackets,name);
}

int main(){
    int n;
    cin>>n;
    vector<int> dim(n);
    for(int i=0;i<n;i++)
        cin>>dim[i];
    MCM(dim,n);
    return 0;
}
