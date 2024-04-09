#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int carAssembly(vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x, int n) {
    vector<int> dp1(n), dp2(n);

    // Base case
    dp1[0] = e[0] + a[0][0]; // Time taken to reach station 1 on line 1
    dp2[0] = e[1] + a[0][1]; // Time taken to reach station 1 on line 2

    // Fill dp1 and dp2 arrays
    for (int i = 1; i < n; ++i) {
        dp1[i] = min(dp1[i - 1] + a[i][0], dp2[i - 1] + t[i - 1][1] + a[i][0]);
        dp2[i] = min(dp2[i - 1] + a[i][1], dp1[i - 1] + t[i - 1][0] + a[i][1]);
    }

    // Return the minimum time to exit
    return min(dp1[n - 1] + x[0], dp2[n - 1] + x[1]);
}

int main() {
    int n; // Number of stations on each assembly line
    cout << "Enter the number of stations: ";
    cin >> n;

    vector<vector<int>> a(n, vector<int>(2)); // Time taken at each station on each line
    cout << "Enter the time taken at each station on line 1 and line 2: ";
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];

    vector<vector<int>> t(n - 1, vector<int>(2)); // Time taken to switch lines
    cout << "Enter the time taken to switch lines: ";
    for (int i = 0; i < n - 1; ++i)
        cin >> t[i][0] >> t[i][1];

    vector<int> e(2); // Entry time for each line
    cout << "Enter entry time for line 1 and line 2: ";
    cin >> e[0] >> e[1];

    vector<int> x(2); // Exit time for each line
    cout << "Enter exit time for line 1 and line 2: ";
    cin >> x[0] >> x[1];

    int minTime = carAssembly(a, t, e, x, n);
    cout << "Minimum possible time by the car chassis to complete: " << minTime << endl;

    return 0;
}
