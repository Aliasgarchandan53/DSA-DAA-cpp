#include <iostream>
#include <climits>
using namespace std;

int max_sub_sum(int[], int, int);
int cross_sum(int arr[], int low, int mid, int high);

int max_sub_sum(int arr[], int low, int high)
{
    if (low == high)
        return arr[low];
    int mid = low + (high - low) / 2;
    int leftsum = max_sub_sum(arr, low, mid);
    int rightsum = max_sub_sum(arr, mid + 1, high);
    int crossSum = cross_sum(arr, low, mid, high);
    return max(crossSum, max(rightsum, leftsum));
}

int cross_sum(int arr[], int low, int mid, int high)
{
    int sum = 0, leftsum = INT_MIN, rightsum = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        if (leftsum < sum)
            leftsum = sum;
    }
    sum = 0;
    for (int i = (mid + 1); i <= high; i++)
    {
        sum += arr[i];
        if (rightsum < sum)
            rightsum = sum;
    }
    return (leftsum + rightsum);
}

int main()
{
    int n;
    cout << "enter length of array :\n";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array :\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int max_sum = max_sub_sum(arr, 0, n - 1);
    cout << "maximum subarray sum is : " << max_sum << endl;
    return 0;
}

// #include <iostream>
// #include <climits>
// using namespace std;

// struct SubarrayInfo {
//     int sum;
//     int start;
//     int end;
// };

// SubarrayInfo max_sub_sum(int arr[], int low, int high);
// int cross_sum(int arr[], int low, int mid, int high);

// SubarrayInfo max_sub_sum(int arr[], int low, int high) {
//     SubarrayInfo result;

//     if (low == high) {
//         result.sum = arr[low];
//         result.start = low;
//         result.end = high;
//         return result;
//     }

//     int mid = low + (high - low) / 2;
//     SubarrayInfo left = max_sub_sum(arr, low, mid);
//     SubarrayInfo right = max_sub_sum(arr, mid + 1, high);
//     SubarrayInfo cross = {0, 0, 0};

//     int left_sum = INT_MIN;
//     int right_sum = INT_MIN;
//     int sum = 0;

//     for (int i = mid; i >= low; i--) {
//         sum += arr[i];
//         if (sum > left_sum) {
//             left_sum = sum;
//             cross.start = i;
//         }
//     }

//     sum = 0;
//     for (int i = mid + 1; i <= high; i++) {
//         sum += arr[i];
//         if (sum > right_sum) {
//             right_sum = sum;
//             cross.end = i;
//         }
//     }

//     cross.sum = left_sum + right_sum;
//     if (left.sum >= right.sum && left.sum >= cross.sum) {
//         return left;
//     } else if (right.sum >= left.sum && right.sum >= cross.sum) {
//         return right;
//     } else {
//         return cross;
//     }
// }

// int main() {
//     int n;
//     cout << "Enter length of array: ";
//     cin >> n;
//     int arr[n];
//     cout << "Enter elements of array:\n";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     SubarrayInfo max_subarray = max_sub_sum(arr, 0, n - 1);
//     cout << "Maximum subarray sum is: " << max_subarray.sum << endl;
//     cout << "Maximum subarray is: ";
//     for (int i = max_subarray.start; i <= max_subarray.end; i++)
//         cout << arr[i] << " ";
//     cout << endl;
//     return 0;
// }
