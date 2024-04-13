#include <bits/stdc++.h>
using namespace std;

void assembly_line_scheduling(int n, vector<vector<int>>& a,vector<vector<int>>& t,vector<int>& e,vector<int>& x)
{
    //initialise dp arrays:
    vector<vector<int>> dp(n,vector<int>(2)); //dp[i][0]-station 1,dp[i][1]-station 2
    vector<vector<int>> line(n,vector<int>(2));//line[i][0]-station 1,line[i][1]-station 2

    //base case 
    dp[0][0] = e[0]+a[0][0];
    dp[0][1] = e[1]+a[0][1];

    //calculating min assesmbly time
    int t11,t12,t21,t22,t_final,l_final;
    for(int i=1;i<n;i++){
        t11 = dp[i-1][0] + a[i][0];
        t12 = dp[i-1][1] + t[i-1][1] +a[i][0];
        
        t21 = dp[i-1][0] + t[i-1][0] +a[i][1];
        t22 = dp[i-1][1] + a[i][1];

        if(t12>=t11){
            dp[i][0]=t11;
            line[i][0]=1;
        }
        else{
            dp[i][0]=t12;
            line[i][0]=2;
        }

        if(t21>=t22){
            dp[i][1]=t22;
            line[i][1]=2;
        }
        else{
            dp[i][1]=t21;
            line[i][1]=1;
        }
    }
    if((dp[n-1][0]+x[0])<=(dp[n-1][1]+x[1])){
        t_final = dp[n-1][0]+x[0];
        l_final = 1;
    }
    else{
        t_final =dp[n-1][1]+x[1];
        l_final = 2;
    }
    cout<<"The minimum exit time is : "<<t_final<<endl;
    cout<<"The line of exit is : "<<l_final<<endl;
}

int main()
{

    int n;
    cout << "Enter number of stations :\n";
    cin >> n;

    vector<vector<int>> s(n,vector<int>(2)) ; // s[0] - station 1 s[1]- station 2
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the entry time of station " << (i + 1) << " by line 1 and 2 :\n";
        cin >> s[i][0] >> s[i][1];
    }
    vector <vector<int>> t(n-1,vector<int>(2));
    for (int i = 0; i < n - 1; i++)
    {
        cout << "Enter the entry time of station " << (i + 2) << " from station " << (i + 1) << " by line 1 and 2 :\n";
        cin >> t[i][0] >> t[i][1];
    }

    vector<int> e(2);
    vector<int> x(2);

    cout << "Enter the entry timings of line 1 and 2 : \n";
    cin >> e[0] >> e[1];
    cout << "Enter the exit timings of line 1 and 2 : \n";
    cin >> x[0] >> x[1];

    assembly_line_scheduling(n,s,t,e,x);

    return 0;
}