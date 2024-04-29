/*LCS*/
#include <bits/stdc++.h>
using namespace std;

void LCS(string &s1,string &s2){
    //initializing    
    int n=s1.length();
    int m=s2.length();

    vector<vector<int>> dp(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1] + 1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<"Longest common subsequence is of length "<<dp[n][m]<<endl;

    //retracing the sequence
    int i=n,j=m;
    string lcs ;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            lcs=s1[i-1]+lcs;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])i--;
        else j--;
    }
    cout<<"Longest common subsequence is "<<lcs<<endl;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    LCS(s1,s2);
    return 0;
}