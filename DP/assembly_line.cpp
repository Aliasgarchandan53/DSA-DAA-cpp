/*Assembly line scheduling
1- station time , entry exit time, station change time,dp of time, dp of line
*/

#include <bits/stdc++.h>
using namespace std;

void assembly_line(vector<vector<int>> &stn,vector<vector<int>> &t,vector<int> &e,vector<int> &x,int n){

    //initialising dp arrays;
    vector<vector<int>> dp(2,vector<int>(n));
    vector<vector<int>> line(2,vector<int>(n));
    dp[0][0] = e[0] +stn[0][0];
    dp[1][0] = e[1] +stn[1][0];
    line[0][0]=1;
    line[1][0]=2;

    int t11,t12,t21,t22,t_f1,t_f2,tf,lf;

    for(int i=1;i<n;i++){

        t11=dp[0][i-1]+stn[0][i];
        t12=dp[1][i-1]+t[1][i-1]+stn[0][i];
        t21=dp[0][i-1]+t[0][i-1]+stn[1][i];
        t22=dp[1][i-1]+stn[1][i];

        if(t11<t12){
            dp[0][i]=t11;
            line[0][i]=1;
        }
        else{
            dp[0][i]=t12;
            line[0][i]=2;
        }

        if(t21<t22){
            dp[1][i]=t21;
            line[1][i]=1;
        }
        else{
            dp[1][i]=t22;
            line[1][i]=2;
        }
    }
    t_f1=dp[0][n-1] + x[0];
    t_f2=dp[1][n-1] + x[1];

    if(t_f1<t_f2){
        tf=t_f1;
        lf=1;
    }
    else{
        tf=t_f2;
        lf=2;
    }
    cout<<"The assembly comes out of the process via line "<<lf<<" in "<<tf<<" minutes.\n";
    cout<<"Assembly path :\n";
    string path = to_string(lf);
    int j=(lf-1);
    for(int i=(n-1);i>=0;i--){
        path+=(" >-- "+to_string(line[j][i]));
        j=(line[j][i]-1);
    }
    reverse(path.begin(),path.end());
    cout<<path<<endl;
}

int main(){
    int n;//no of stations
    cin>>n;
    vector<vector<int>> stn(2,vector<int>(n));
    vector<vector<int>> t(2,vector<int>(n-1));
    vector<int> e(2);
    vector<int> x(2);
    for(int i=0;i<n;i++)
        cin>>stn[0][i]>>stn[1][i];
    for(int i=0;i<n-1;i++)
        cin>>t[0][i]>>t[1][i];
    cin>>e[0]>>e[1];
    cin>>x[0]>>x[1];
    assembly_line(stn,t,e,x,n);
    return 0;
}
