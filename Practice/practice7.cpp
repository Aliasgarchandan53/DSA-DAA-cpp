/* Rabin Karp Matcher
    hash = (hash*10 + (str[i]-'0')))%q; return hash
    new_hash = (old_hash - (old_char-'0') * <int>(pow(10,len-1))) %q;
    new_hash = (new_hash*10 +(new_char-'0')) %q
        return (new_hash>0?new_hash:(new_hash+q))
*/

#include <bits/stdc++.h>
using namespace std;

int calculate_hash(string &str,int len, int q){
    int hash=0;
    for(int i=0;i<len;i++)
        hash = (hash*10 +(str[i]-'0'))%q;
    return hash;
}

int update_hash(int old_hash,char old_char, char new_char,int len,int q){
    int new_hash = (old_hash - (old_char-'0') * static_cast<int>(pow(10,len-1))) %q;
    new_hash = (new_hash*10 +(new_char-'0')) %q;
    return (new_hash>0?new_hash:(new_hash+q));
}

void Rabin_Karp_matcher(string &text, string &pattern,int q){
    int n = text.length();
    int m = pattern.length();
    int phash = calculate_hash(pattern,m,q);
    int thash = calculate_hash(text,m,q);
    int sp_hits=0;

    for(int i=0;i<=(n-m);i++){
        if(thash==phash){
            int j;
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j])
                    break;
            }
            if(j==m)
            cout<<"Match found at index "<<i<<endl;
            else
                sp_hits++;
        }
        if(i<(n-m))
            thash = update_hash(thash,text[i],text[i+m],m,q);
    }
    cout<<"The number of spurious hits encountered are :"<<sp_hits<<endl;
}

int main(){
    string text,pattern;int q;
    cout<<"Enter the text string :\n";
    cin>>text;
    cout<<"Enter the pattern string :\n";
    cin>>pattern;
    cout<<"Enter the hash modulus :\n";
    cin>>q;
    Rabin_Karp_matcher(text,pattern,q);
    return 0;
}