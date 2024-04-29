/*Subset sum using backtracking :
1- result array, curr_set,current_index, target_sum , array of elements
2- function subset_sum - currset init, sort array, calls backtrack
3- bracktrack sub sum - to perform the algo
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack_subset_sum(int index,vector<int> &arr, vector<vector<int>> &result, vector<int> &curr_set,int target){

    //base case
    if(target==0){
        result.push_back(curr_set);
        return;
    }
    //backtracking algorithm
    for(int i=index;i<arr.size();i++){
        if(i<index && arr[i-1]==arr[i])//to avoid duplicates
            continue;
        if(arr[i]>target)//as array is sorted, all elements ahead will not be a part of solution as well
            break;
        
        curr_set.push_back(arr[i]);//exploring a particular node
        backtrack_subset_sum(i+1,arr,result,curr_set,target-arr[i]);
        curr_set.pop_back(); // when a node is explored, it is removed to explore other possibilities
        
    }
}

void subset_sum(vector<int> &arr,int target){

    vector<vector<int>> result;
    vector<int> curr_set;
    sort(arr.begin(),arr.end());
    backtrack_subset_sum(0,arr,result,curr_set,target);

    //printing possible subsets
    for(auto subset : result){
        cout<<"[ ";
        for(auto num : subset){
            cout<<num<<", ";
        }
        cout<<"]\n";
    }
}

int main(){
    int n,target;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>target;
    subset_sum(arr,target);
    return 0;
}