#include <iostream>
#include <string>
using namespace std;

bool isDistinct(string pattern)
{
    for (int i = 0; i < pattern.length(); i++)
    {
        for (int j = i + 1; j < pattern.length(); j++)
        {
            if (pattern[i] == pattern[j])
            {
                return false;
            }
        }
    }
    return true;
}

int naive_pattern_match_algo(string str, string pattern)
{
    int m = pattern.length();

    for (int i = 0; i < (str.length() - m + 1); i++)
    {
        bool found = true;
        for (int j = 0; j < m; j++)
        {
            if (str[i + j] != pattern[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str;
    cout << "Enter the string X : \n";
    cin >> str;
    int n;
    cout << "Enter the number of characters in the pattern P :\n";
    cin >> n;
    string pattern;

    char c;
    cout << "Enter " << n << " distinct characters in your pattern P :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c != ' ')
            pattern += c;
    }

    if (!isDistinct(pattern))
    {
        cout << "Pattern should have distinct characters." << endl;
        return 1;
    }
    cout << "The string is " << str << " and the pattern is " << pattern << endl;
    int result = naive_pattern_match_algo(str, pattern);
    cout << "Index of match is " << result << endl;
    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// int naive_pattern_match_algo(string str, string pattern, int m)
// {
//     for (int i = 0; i < (str.length() - m +1); i++)
//     {
//         if (str[i] == pattern[0])
//         {
//             int j;
//             for (j = i; j < (i + m); j++)
//             {
//                 if (str[j] != pattern[j - i])
//                     break;
//             }
//             if (j - i == m)
//                 return i;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     string str;
//     cout << "Enter the string : \n";
//     cin >> str;
//     int n;
//     cout << "Enter the number of characters in the pattern :\n";
//     cin>>n;
//     string pattern;
// char c;
// cout << "Enter n space-separated characters in your pattern :\n";
// for (int i = 0; i < n; i++)
// {
//     cin >> c;
//     if (c != ' ')
//         pattern += c;
// }
//     cout << "The string is " << str << " and the pattern is " << pattern << endl;
//     int result = naive_pattern_match_algo(str, pattern, n);
//     cout << "Index of match is " << result << endl;
//     return 0;
// }