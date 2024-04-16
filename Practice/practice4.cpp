/* Assembly line scheduling time for i'th station:
    dp[i][0] = min(dp[i-1][0] + a[i][0] , dp[i-1][1] + a[i][0] +t[i-1][1]) 
    dp[i][1] = min(dp[i-1][1] + a[i][1] , dp[i-1][0] + a[i][1] +t[i-1][0])
*/

#include <bits/stdc++.h>
using namespace std;

void assembly_line(vector<vector<int>> &a,vector<vector<int>> &t,vector<int> &e,vector<int> &x,int n){

    //initialising dp and line arrays:
    vector<vector<int>> dp(n,vector<int>(2,0));
    vector<vector<int>> line(n,vector<int>(2,0));
    int final_line,final_time ,t11,t12,t21,t22,t1f,t2f;
    
    //initialise index 0 :
    dp[0][0] = a[0][0] + e[0];
    dp[0][1] = a[0][1]+e[1];
    line[0][0]=1;line[0][1]=2;

    //assembly line scheduling :
    for(int i=1;i<n;i++){
        t11 = dp[i-1][0] + a[i][0];
        t12 = dp[i-1][1] + a[i][0] +t[i-1][1];
        t21 = dp[i-1][0] + a[i][1] +t[i-1][0];
        t22 = dp[i-1][1] + a[i][1];

        if(t11<t12){
            dp[i][0] = t11;
            line[i][0] = 1;
        }
        else{
            dp[i][0] = t12;
            line[i][0] = 2;
        }
        if(t21<t22){
            dp[i][1] = t21;
            line[i][1] = 1;
        }
        else{
            dp[i][1] = t22;
            line[i][1] = 2;
        }
    }
    t1f = dp[n-1][0] +x[0];
    t2f = dp[n-1][1] +x[1];
    if(t1f<t2f){
        final_time = t1f;
        final_line = 1;
    }
    else{
        final_time = t2f;
        final_line = 2;
    }

    cout<<"Minimum exit time is "<<final_time<<" units and assembly exits from line "<<final_line<<endl;
}

int main(){
    int n;
    cout<<"Enter no. of stations \n";
    cin>>n;
    vector<vector<int>> a(n,vector<int>(2));
    vector<vector<int>> t(n-1,vector<int>(2));
    vector<int> e(2),x(2);

    for(int i=0;i<n;i++){
        cout<<"Enter time taken at station "<<(i+1)<<" on line 1 and 2 :\n";
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=0;i<n-1;i++){
        cout<<"Enter time taken to enter from station "<<(i+1)<<" to station "<<(i+2)<<" by line 1 and 2 :\n";
        cin>>t[i][0]>>t[i][1];
    }
    cout<<"Enter entry time of line 1 and 2\n";
    cin>>e[0]>>e[1];
    cout<<"Enter exit time of line 1 and 2\n";
    cin>>x[0]>>x[1];

    assembly_line(a,t,e,x,n);

    return 0;
}