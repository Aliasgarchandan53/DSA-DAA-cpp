#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int max = nums.size();
    int sum = (max*(max+1))/2;
    for(int i=0;i<nums.size();i++){
        sum-=nums[i];
    }
    return sum;
}

int main(){
    vector<int> nums; int n=0;
    cout<<"Enter numbers in array (-1 for exit): \n";
    while(n!=-1){
        cin>>n;
        if(n!=-1)
            nums.push_back(n);
    }
    int miss = missingNumber(nums);
    cout<<"Missing number is "<<miss<<endl;
    return 0;
}