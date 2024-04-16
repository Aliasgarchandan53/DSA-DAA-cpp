/* Subset sum using backtracking
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack_subset_sum(int index,vector<int> &arr,vector<vector<int>> &result, vector<int> &curr_set,int target){
    if(target==0){
        result.push_back(curr_set);
        return;
    }

    //backtracking :
    for(int i =index;i<arr.size();i++){
        if(i>index && arr[i-1]==arr[i])
            continue;
        if(arr[i]>target) 
            break;
        
        curr_set.push_back(arr[i]);
        backtrack_subset_sum(i+1,arr,result,curr_set,target-arr[i]);
        curr_set.pop_back();
    }
}

void subset_sum(vector<int> &arr,vector<vector<int>> &result ,int target){
    sort(arr.begin(),arr.end());
    vector<int> curr_set;
    backtrack_subset_sum(0,arr,result,curr_set,target);
}

int main(){
    int n,target;
    cout<<"Enter the number of elements in array \n";
    cin>>n;
    vector<int> arr(n);
    vector<vector<int>> result;

    cout<<"enter array elements :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Enter targeted sum of subset :\n";
    cin>>target;
    subset_sum(arr,result,target);
    cout<<"The possible subsets are :\n";
    for(auto row:result){
        cout<<"[ ";
        for(auto num:row)
            cout<<num<<" ";
        cout<<"]\n";
    }

    return 0;
}