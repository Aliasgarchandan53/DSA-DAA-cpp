#include <iostream>
#include <vector>
using namespace std; 
 
void rotate(vector<int>& nums, int k) {
  for(int i=0;i<k;i++){
    nums.insert(nums.begin(),nums[nums.size()-1]);
    nums.pop_back();
  }      
}


int main(){
    vector <int> nums;
    cout<<"Enter integers in array (-1 to exit) : \n";
    int n;
    while(n!=-1){
        cin>>n;
        if(n!=-1)
            nums.push_back(n);
    }
    int rot;
    cout<<"Enter number of elements to rotate:\n";
    cin>>rot;
    rotate(nums,rot);
    for(auto it:nums)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}