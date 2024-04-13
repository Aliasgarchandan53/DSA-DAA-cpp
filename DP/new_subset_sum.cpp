#include <bits/stdc++.h>
using namespace std;

void backtrack_subset_sum(int index,vector<int> &arr , vector<vector<int>> &result, vector<int> &current_set, int target){

    //base case 
    if(target==0){
        result.push_back(current_set);
        return;
    }

    for(int i=index;i<arr.size();i++){

        //duplicates 
        if(i>index && arr[i]==arr[i-1])
            continue;
        //if element>target, all elements ahead will be greater as we passed a sorted array.
        if(arr[i]>target)
            break;

        //backtrack and find subsets
        current_set.push_back(arr[i]);
        backtrack_subset_sum(i+1,arr,result,current_set,(target-arr[i]));
        current_set.pop_back();
        
    }
}

void subset_sum(vector<int> &arr , vector<vector<int>> &result,int target){
    sort(arr.begin(),arr.end());
    vector<int> curr_set;
    backtrack_subset_sum(0,arr,result,curr_set,target);
}

int main(){
    int n,target;
    cout<<"Enter the number of elements in the array : \n";
    cin>>n;

    vector<int> arr(n);
    vector<vector<int>> result;

    cout<<"Enter the elements of array(space separated) :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter the targeted sum of subsets : \n";
    cin>>target;

    subset_sum(arr,result,target);

    cout<<"Subsets with target sum = "<<target<<" are :\n";
    for(auto it:result){
        cout<<"[ ";
        for(auto num:it){
            cout<<num<<" ";
        }
        cout<<"]\n";
    }

    return 0;   
}