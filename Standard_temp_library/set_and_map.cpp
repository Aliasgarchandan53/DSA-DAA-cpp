#include <bits/stdc++.h>
using namespace std;

int main(){

    //sorted and unique elements
    set <int> s;//stores unique elements in a sorted order
    s.insert(10);
    s.emplace(21);
    s.insert(7);
    s.insert(60);
    // cout<<*(s.find(33))<<endl;//points at end of set if element is absent.
    // cout<<s.count(30)<<endl;//0 if absent
    // cout<<s.count(21)<<endl;//1 if present
    // cout<<s.erase(10)<<endl;
    // for(auto it:s){
    //     cout<<it<<" ";
    // }
    auto it = s.lower_bound(70);
    // cout<<*(--it)<<endl;
    // cout<<*(s.upper_bound(7))<<endl;

    //multiset- sorted elements with multiple occurences as well 
    
    multiset <int> ms;
    int m;
    // while(m!=-1){
    //     cin>>m;
    //     if(m!=-1)ms.insert(m);
    // }

    // for(auto it:ms)cout<<it<<" ";
    // cout<<ms.count(1);
    ms.erase(ms.find(1));//do not give value as parameter as it removes all occurences of that value. Rather, give iterator.
    //all other set functions are same.

    //unordered set : T(n) = O(1) in most cases. worst time O(n) --randomised order
    unordered_set <int> us;//all set methods are same but order is random.
    //upper bound and lower bound methods do not work for this data type.

    //map : a data structure storing data as {key-value} pair in a sorted order of keys*
    map <string , int> mp;
    mp["ali"]=20;
    mp.emplace("abbas",22);
    mp.insert({"taher",19});
    // for(auto it: mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    map <int,string> mp2 ;
    mp2.insert({1,"he"});
    mp2.insert({2,"she"});
    mp2.insert({3,"him"});
    mp2.insert({4,"her"});
    mp2.insert({5,"it"});
    auto its = mp2.find(2);//find accepts keys as arguments
    cout<<its->second<<endl;
    // for(auto it=mp.begin();it!=mp.end();it++)
    //     cout<<it->second<<" ";

    // similarly we have  multimap and multiset
    
    return 0;
}