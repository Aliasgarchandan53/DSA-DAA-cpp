#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Rabin_karp_matcher
{
public:
    int n, m;
    string text, pattern;
    Rabin_karp_matcher(string text, string pattern)
    {
        this->text = text;
        this->pattern = pattern;
        n = text.length();
        m = pattern.length();
    }

    int new_hash(string s)
    {
        int arr[s.length()]; 
        for (int i = 0; i < s.length(); i++)
        {
            arr[i] = s[i] - '0'; 
        }
        int sum = 0;
        int m = s.length(); 
        for (int i = 0; i < m; i++)
            sum += (arr[i] * pow(10, m - 1 - i)); 
        int hash = sum % 10;
        return hash;
    }
    int next_hash(int prev_hash, int next_digit)
    {
        int hash = (prev_hash - (prev_hash % int(pow(10, 4)) * int(pow(10, 4)))) * 10 + next_digit;
        return hash;
    }
    void Rab_Karp_Matcher()
    {
        int p_hash = new_hash(pattern);
        int hash1 = new_hash(text.substr(0, 5));
        int step = -1;
        int prev_hash = hash1;
        bool flag = false;
        int sp_hits = 0;
        if (p_hash == hash1)
        {
            int i;
            for (i = 0; i < m; i++)
            {
                if (text[i] != pattern[i])
                {
                    break;
                }
            }
            if (i == m - 1)
                flag = true;
            else
                sp_hits++;
        }

        if (!flag)
        {
            for (int i = 1; i < (n - m); i++)
            {
                int curr_hash = next_hash(prev_hash, (text[i] - '0'));
                prev_hash=curr_hash;
                if (curr_hash = p_hash)
                {

                    int j;
                    for (j = i; j < (i + m); j++)
                    {
                        if (text[j] != pattern[j - i])
                            break;
                    }

                    if (j - i == m)
                    {
                        step = i;
                    }
                    else
                        sp_hits++;
                }
            }
        }
        cout << "The pattern matches at index " << step << " and the number of spurious hits are " << sp_hits << endl;
    }
};

int main()
{
    Rabin_karp_matcher r1("2359023141526739921", "31415");
    r1.Rab_Karp_Matcher();
    return 0;
}
