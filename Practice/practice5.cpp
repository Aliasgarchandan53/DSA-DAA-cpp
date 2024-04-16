/* matrix chain multiplication:
    Multiplication function :
        m[i][j] = min(m[i][j],m[i][k] + m[k+1][j] + d[i-1]*d[k]*d[j];) 
        loops : 1- all length chains from 2 to n 
        2-starting points of each chain from i=0 to chain length l
            j - end point of each chain of length l
        3- all possible partitions of length k in each chain of length l
    Print parenthesis :
        recursive function with args as 2 indices and bracket array, char

    Note : all arrays start from 1 to n so pass n= (n+1) in MCM
*/

#include <bits/stdc++.h>
using namespace std;

void printOptimalOrder(int i,int j,vector<vector<int>> &brackets,char &name){
    if(i==j){
        cout<<name++;
        return ;
    }
    cout<<"(";
    printOptimalOrder(i,brackets[i][j],brackets,name);
    printOptimalOrder(brackets[i][j]+1,j,brackets,name);
    cout<<")";
}

void MCM(vector<int> &d ,int n){

    //initialise dp array:
    vector<vector<int>> dp(n,vector<int>(n));
    vector<vector<int>> brackets(n,vector<int>(n));
    for(int i=1;i<n;i++)
        dp[i][i]=0;

    //calculation of minimum multiplications :
    for(int l=2;l<n;l++){
        for(int i=1;i<(n-l+1);i++){
            int j = (i+l-1);
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                int q = dp[i][k] + dp[k+1][j] + d[i-1]*d[j]*d[k];
                if(dp[i][j]>q){
                    dp[i][j]=q;
                    brackets[i][j]=k;
                }
            }
        }
    }

    cout<<"Minimum multiplications needed are "<<dp[1][n-1]<<endl;
    cout<<"Optimal parenthization : \n";
    char name ='A';
    printOptimalOrder(1,n-1,brackets,name);//give 1-n where n is length of dimension array 
}

int main(){
    int n;
    cout<<"Enter no of matrices :\n";
    cin>>n;
    vector<int> dim(n+1);
    cout<<"Enter dimesions :\n";
    for(int i=0;i<(n+1);i++)   
        cin>>dim[i];
     
    MCM(dim,n+1);
    return 0;
}