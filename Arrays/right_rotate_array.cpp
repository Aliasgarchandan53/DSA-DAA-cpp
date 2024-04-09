#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    k = (k % nums.size());
    reverse(nums.begin() + (nums.size() - k), nums.end());
    reverse(nums.begin(), nums.begin() + (nums.size() - k));
    reverse(nums.begin(), nums.end());
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
    int rot;
    cout << "Enter number of elements to rotate:\n";
    cin >> rot;
    rotate(nums, rot);
    for (auto it : nums)
        cout << it << " ";
    cout << endl;
    return 0;
}