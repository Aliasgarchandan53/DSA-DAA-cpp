#include <bits/stdc++.h>
using namespace std;

int main(){
    pair <int,int> p ={2,4};
    cout<<p.first<<" "<<p.second<<endl;

    pair <int ,pair<int,int>> p2 = {1,{2,3}};
    cout<<p2.second.second<<endl;

    pair<int,int> arr[]={
        {3,4},{5,6},{7,8}
    };
    cout<<arr[2].first<<endl;
    return 0;
}