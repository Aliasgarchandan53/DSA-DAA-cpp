#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here 
    int i = 0;
    int j = 0;
    vector<int> uni;
    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            if (!uni.empty())
            {
                if (a[i] != uni[uni.size() - 1])
                    uni.push_back(a[i++]);
                else
                    i++;
            }
            else
                uni.push_back(a[i++]);
        }
        else if (a[i] > b[j])
        {
            if (!uni.empty())
            {
                if (b[j] != uni[uni.size() - 1])
                    uni.push_back(b[j++]);
                else
                    j++;
            }
            else
                uni.push_back(b[j++]);
        }
        else
        {
            if (!uni.empty())
            {
                if (a[i] != uni[uni.size() - 1])
                {
                    uni.push_back(a[i++]);
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            else
            {
                uni.push_back(a[i++]);
                j++;
            }
        }
    }
    for (; i < a.size(); i++)
    {
        if (a[i] != uni[uni.size() - 1])
            uni.push_back(a[i]);
    }
    for (; j < b.size(); j++)
    {
        if (b[j] != uni[uni.size() - 1])
            uni.push_back(b[j]);
    }
    return uni;
}

int main()
{
    vector<int> nums1;
    cout << "Enter integers in array1 (-1 to exit) : \n";
    int n;
    while (n != -1)
    {
        cin >> n;
        if (n != -1)
            nums1.push_back(n);
    }
    vector<int> nums2;
    cout << "Enter integers in array2 (-1 to exit) : \n";
    int m;
    while (m != -1)
    {
        cin >> m;
        if (m != -1)
            nums2.push_back(m);
    }
    vector<int> uni = sortedArray(nums1, nums2);
    for (auto it : uni)
        cout << it << " ";
    cout << endl;
    return 0;
}