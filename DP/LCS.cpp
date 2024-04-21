#include <iostream>
#include <vector>

using namespace std;

string longestCommonSubsequence(const string &A, const string &B)
{
    int n = A.length();
    int m = B.length();

    // Create a table to store the lengths of longest common subsequence
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the longest common subsequence
    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            lcs = A[i - 1] + lcs;
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
        {
            --j;
        }
    }

    return lcs;
}

int main()
{
    int n, m;
    cout << "Enter the lengths of strings :\n";
    cin >> n >> m;

    char A[n];
    char B[m];
    cout << "Enter the strings (character separated) :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    string S1 = "", S2 = "";
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++)
        S1 += A[i];

    for (int i = 0; i < m; i++)
        S2 += B[i];

    cout << S1 << " " << S2 << endl;
    string result = longestCommonSubsequence(S1, S2);
    cout << "Length of Longest Common Subsequence : " << result.length() << endl;
    cout << "Longest common subsequence: " << result << endl;
    return 0;
}
