#include <iostream>
#include <vector>
#include <string>
using namespace std;

// vector<int> printNos(int x) {
//     vector<int> nums;
//     cout<<"running.."<<endl;
//     // Write Your Code Here
//     if (x == 0) {
//       return nums;
//     }
//     if(x==1){
//         nums.push_back(x);
//         return nums;
//     }
//     nums = printNos(x-1);
//     nums.push_back(x);
//     return nums;
// }
// vector<string> printNTimes(int n) {
// 	// Write your code here.
// 	vector<string> ninjas;
// 	if(n==0)
// 		return ninjas;
// 	ninjas = printNTimes(n-1);
// 	ninjas.push_back("Coding Ninjas ");
// 	return ninjas;
// }

// vector<int> reverseArray(int n, vector<int> &nums)
// {
//     int mid = (nums.size()-1/2);
//     if(n<=mid){
//         return nums;
//     }
//     swap(nums[nums.size()-n],nums[n-1]);
//     reverseArray(n-1, nums);
//     return nums;
// }
//  bool isPalindrome(string s) {
//     for (char& c : s) {
//         if (std::isalnum(c)) {
//             c = std::tolower(c);
//         } else {
//             c = '\0';
//         }
//     }
//     cout<<s<<endl;
//         if(s.length()==0)
//             return true;
//         if(s[0]!=s[s.length()-1])
//             return false;
//         string s1 = s.substr(1,s.length()-2);
//         return isPalindrome(s1);
//     }

bool isPalindrome(string s) {
    // Modify the string in place
    for (char& c : s) {
        if (std::isalnum(c)) {
            c = std::tolower(c);
        } else {
            c = '\0';
        }
    }

    cout << s << endl;

    if (s.length() <= 1) {
        return true;
    }

    if (s[0] != s[s.length() - 1]) {
        return false;
    }

    string s1 = s.substr(1, s.length() - 2);

    // Return the result of the recursive call
    return isPalindrome(s1);
}

int main(){ 
    if(isPalindrome("A man, a plan, a canal: Panama"))
    cout<<"string is palindrome"; 
    else    
        cout<<"string is not palindrome.";
    return 0;
}