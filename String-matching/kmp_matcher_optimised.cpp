#include <bits/stdc++.h>
using namespace std;

void construct_LPS_table(string &pattern , vector<int> &lps,int m){
    
    int i=1,j=0;
    while(i<m){
        if(pattern[i]==pattern[j])
            lps[i++]=(++j);
        else{
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
}

void kmp_matcher(string &text,string &pattern , vector<int> &lps){
    int m =pattern.length();
    construct_LPS_table(pattern,lps,m);
    int i=0,j=0;

    while(i<text.length()){
        if(text[i]==pattern[j]){
            i++;j++;
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
    string Text , Pattern;
    cout<<"Enter the text string :\n";
    cin>>Text;
    cout<<"Enter the pattern string :\n";
    cin>>Pattern;
    vector<int> LPS(Pattern.length(),0);
    kmp_matcher(Text,Pattern,LPS);
    return 0;
}