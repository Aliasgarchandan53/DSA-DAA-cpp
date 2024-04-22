#include <bits/stdc++.h>
using namespace std;

int zero_one_knapsack(vector<int> &weight, vector<int> &value, int n, int W, vector<bool> &selected_items) {
    // dp initialization
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int i = weight[0]; i <= W; i++) dp[0][i] = value[0];

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int not_taken = 0 + dp[i - 1][w];
            int taken = INT_MIN;
            if (weight[i] <= w)
                taken = value[i] + dp[i - 1][w - weight[i]];
            dp[i][w] = max(taken, not_taken);
        }
    }

    // tracing back to find selected items
    int remaining_weight = W;
    for (int i = n - 1; i >= 0; i--) {
        if (i == 0) {
            if (dp[i][remaining_weight] > 0)
                selected_items[i] = true;
        } else if (dp[i][remaining_weight] != dp[i - 1][remaining_weight]) {
            selected_items[i] = true;
            remaining_weight -= weight[i];
        }
    }

    return dp[n - 1][W];
}

int main() {
    int n, W;
    cin >> n; // number of articles
    vector<int> weight(n);
    vector<int> value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];
    cin >> W;
    vector<bool> selected_items(n, false);
    int maxval = zero_one_knapsack(weight, value, n, W, selected_items);
    cout << "Maximum profit gathered is " << maxval << " units." << endl;
    cout << "Selected items: ";
    for (int i = 0; i < n; i++) {
        if (selected_items[i])
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
