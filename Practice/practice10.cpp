//KMP matcher
#include <bits/stdc++.h>
using namespace std;

void compute_LPS_table(vector<int> &lps,string &pattern,int m){
    int i=1,j=0;
    while(i<m){
        if(pattern[i]==pattern[j])
            lps[i++]=(++j);
        else{
            if(j!=0)
                j=lps[j-1];
            else
                lps[i++]=0;
        }
    }
}

void KMP_matcher(string &text, string &pattern){
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    compute_LPS_table(lps,pattern,m);
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++,j++;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else    
                i++;
        }
        if(j==m){
            cout<<"Match found at "<<(i-j)<<endl;
            j=lps[j-1];
        }
    }
}

int main(){
    string text,pattern;int q;
    cout<<"Enter the text string :\n";
    cin>>text;
    cout<<"Enter the pattern string :\n";
    cin>>pattern;
    KMP_matcher(text,pattern);
    return 0;
}