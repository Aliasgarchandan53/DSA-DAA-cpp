#include <bits/stdc++.h>
using namespace std;

int LCS(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(i<0 || j<0)
        return 0;
    if(dp[i+1][j+1]!=-1)
        return dp[i+1][j+1];
    if(s1[i]==s2[j])
        return (dp[i+1][j+1] = (1 + LCS(i-1,j-1,s1,s2,dp)));
    
    return (dp[i+1][j+1]=max(LCS(i-1,j,s1,s2,dp),LCS(i,j-1,s1,s2,dp)));
}

int main(){
    string s1,s2;
    cout<<"Enter the strings :\n";
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    int result=LCS(m-1,n-1,s1,s2,dp);
    cout<<"The longest common subsequence is "<<result<<" characters long"<<endl;

    cout<<"The dp array is :\n";
    for(auto row:dp){
        for(auto num:row){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    string s;
    int i=m,j=n;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s=s1[i-1] +s;
            i--;j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else
            j--;
    }
    cout<<"The longest common subsequence is : "<<s<<endl;
    return 0;
}