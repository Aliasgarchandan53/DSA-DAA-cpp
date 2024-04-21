#include <bits/stdc++.h>
using namespace std;

void LCS(string &s1,string &s2){

    int m=s1.length();
    int n=s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));//dp array

    //initialising: 
    for(int i=0;i<=m;i++)
        dp[i][0]=0;
    for(int j=0;j<=n;j++)
        dp[0][j]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    string subseq;
    int i=m,j=n;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            subseq=s1[i-1]+subseq;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else 
            j--;
    }

    cout<<"The longest common subsequence is of length "<<subseq.length()<<endl;
    cout<<"The longest common subsequence is "<<subseq<<endl;
}

int main(){
    string s1,s2;
    cout<<"Enter the strings :\n";
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    LCS(s1,s2);
    return 0;
}