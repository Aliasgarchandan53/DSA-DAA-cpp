#include <bits/stdc++.h>
using namespace std;

void comb2(int ind, vector<int> &candidates, vector<vector<int>> &result, vector<int> &ds, int target)
{
    if (target == 0)
    {
        result.push_back(ds);
        return;
    }

    for (int i = ind; i < candidates.size(); i++)
    {
        if (i > ind && candidates[i] == candidates[i - 1])
        {
            continue;
        }

        if (candidates[i] > target)
        {
            break;
        }

        ds.push_back(candidates[i]);
        comb2(i + 1, candidates, result, ds, target - candidates[i]);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    comb2(0, candidates, result, ds, target);
    return result;
}

int main()
{

    int n, d;
    cout << "Enter the size of array" << endl;
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    cout << "Enter the value of d" << endl;
    cin >> d;

    vector<vector<int>> solutions = combinationSum2(candidates, d);

    cout << "Subsets of the given set whose sum is equal to the given d:" << endl;
    for (const auto &array : solutions)
    {
        for (const int &row : array)
        {
            cout << row << " ";
        }
        cout << endl;
    }
}