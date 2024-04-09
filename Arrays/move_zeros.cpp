#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
void moveZeroes(vector<int> &nums) 
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if(nums[j]!=0){
            if(nums[i]=nums[j])
                i++;
            else    
                nums[i++]=nums[j];
        }
    }
    for (int j = i; j < nums.size(); j++)
    {
        nums[j] = 0;
    }
}

int main()
{
    vector<int> nums;
    cout << "Enter integers in array (-1 to exit) : \n";
    int n;
    while (n != -1)
    {
        cin >> n;
        if (n != -1)
            nums.push_back(n);
    }
    moveZeroes(nums);
    for (auto it : nums)
        cout << it << " ";
    cout << endl;
    return 0;
}