#include <bits/stdc++.h>
using namespace std;

int main(){
        int n,ans;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    unordered_map<int,int> frequency;
    for(auto it:arr){
        if(frequency.find(it)==frequency.end())
            frequency.insert({it,1});
        else
            frequency[it]++;
    }
    ans=arr[0];
    for(auto entry:frequency){
        if(entry.second==1){
            ans=entry.first;
            break;
        }
    }
    cout<<ans;
    return 0;
}