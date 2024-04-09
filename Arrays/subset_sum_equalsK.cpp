#include <iostream>
#include <vector>
using namespace std; 

bool subset_sum(int index, vector<int> &arr, int sum){
    if(index == (arr.size()-1)){ 
        if(sum>arr[index])
            return false;
    }
    if(sum-arr[index]<0)
        return false;
    if(sum-arr[index] == 0){
        return true;}
    bool not_taken=subset_sum(index+1,arr,sum);
    bool taken = subset_sum(index+1,arr,sum-arr[index]);
    return (taken||not_taken);
}

int main(){
    vector<int> nums;
    cout<<"Enter the array(-1 for exit) :\n";
    int n,sum;
    cin>>n;
    while(n!=-1){
        nums.push_back(n);
        cin>>n;
    }
    cout<<"Enter the subset sum:\n";
    cin>>sum;
    bool sum_exists=subset_sum(0,nums,sum);
    if(sum_exists)
        cout<<"Subset exists with sum = "<<sum<<endl;
    else
        cout<<"No such subset exists";
    return 0;
}