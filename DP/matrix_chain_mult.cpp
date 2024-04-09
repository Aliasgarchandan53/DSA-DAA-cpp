// #include <iostream>
// #include <climits>
// using namespace std;

// int MCM(int arr[] , int n){
//     int dp[6][6];

//     //base case copied
//     for(int i=1;i<n;i++)
//         dp[i][i]=0;

//     //dp
//     for(int i=(n-1);i>=1;i--){
//         for(int j=(i+1);j<n;j++){

//             int mini = INT16_MAX;

//             for(int k=i;k<j;k++){

//                 int steps = ( arr[i-1]*arr[k]*arr[j] +dp[i][k] + dp[k+1][j]);

//                 if(steps<mini)
//                     mini=steps;
//             }

//             dp[i][j]=mini;
//         }
//     }
//     return dp[1][n-1];
// }

// int main(){
//     int dim[6]={4,10,3,12,20,7};
//     int mult= MCM(dim, 6);
//     cout<<"minimum "<<mult<<" multiplications are needed.";
//     return 0;
// }

#include <iostream>
#include <climits>
using namespace std;

int MCM(int arr[], int n, int** brackets) {
    int dp[n][n];

    // Base case 
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // DP
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    brackets[i][j] = k;
                }
            }
        }
    }
    return dp[1][n - 1];
}

void printOptimalParenthesization(int i, int j, int** brackets, char &name) {
    if (i == j) {
        cout << name++;
        return;
    }

    cout << "(";

    printOptimalParenthesization(i, brackets[i][j], brackets, name);
    printOptimalParenthesization(brackets[i][j] + 1, j, brackets, name);

    cout << ")";
}

void printOptimalOrder(int** brackets, int n) {
    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printOptimalParenthesization(1, n - 1, brackets, name);
}

int main() {
    int n; // Number of matrices
    cout << "Enter the number of matrices: ";
    cin >> n;

    int dim[n + 1]; // Array to store dimensions
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i < n + 1; ++i)
        cin >> dim[i];

    // Allocate memory for the brackets array
    int** brackets = new int*[n + 1];
    for (int i = 0; i < n + 1; ++i)
        brackets[i] = new int[n + 1];

    int mult = MCM(dim, n + 1, brackets);
    cout << "Minimum " << mult << " multiplications are needed." << endl;

    printOptimalOrder(brackets, n + 1);

    // Free dynamically allocated memory
    for (int i = 0; i < n + 1; ++i)
        delete[] brackets[i];
    delete[] brackets;

    return 0;
}
