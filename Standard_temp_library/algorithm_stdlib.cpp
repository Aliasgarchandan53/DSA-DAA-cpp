#include <bits/stdc++.h>
using namespace std;

bool compare(pair <int,int> p1, pair <int,int>p2){
    if(p1.first>p1.second) return false;
    if(p1.first<p1.second)return true;
    if(p2.first>p2.second) return false;
    return true;
}

int main(){

    int m,n;
    vector <pair<int,int>> arr;
    for(int i=0;i<5;i++){
        cout<<"Enter a pair of integers :\n";
        cin>>m;
        cin>>n;
        arr.push_back({m,n});
    }
    sort(arr.begin(),arr.end(),compare);//sorting according to a custom comparator
    for(auto it:arr){
        cout<<it.first<<","<<it.second<<endl;
    }

    //permutations, set bits and max element

    cout<<__builtin_popcount(23)<<endl;//counts no. of set bits
    cout<<__builtin_popcountll(128635486484)<<endl;//counts no. of set bites

    string s1 = "date";
    sort(s1.begin(),s1.end());
    do{
        cout<<s1<<endl;
    }while(next_permutation(s1.begin(),s1.end()));
    return 0;
}