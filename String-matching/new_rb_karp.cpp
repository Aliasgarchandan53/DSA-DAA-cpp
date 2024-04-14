#include <bits/stdc++.h>
using namespace std;

int calculate_hash(const string &str,int q,int len){
    int hash=0;
    for(int i=0;i<len;i++){
        hash = (hash*10 + (str[i] - '0'))%q;
    }
    return hash;
}

int update_hash(int old_hash,char old_char,char new_char,int q,int len){
    int new_hash = (old_hash - (old_char-'0')*static_cast<int>(pow(10,len-1)))%q;
    new_hash = (new_hash*10 + (new_char -'0')) %q;
    return (new_hash>0?new_hash:(new_hash+q));
}

void rabin_karp(const string &T,const string &P,int q){

    int n = T.length();
    int m = P.length();

    int phash = calculate_hash(P,q,m);
    int thash = calculate_hash(T,q,m);

    int spurious_hits=0;

    for(int i=0;i<=(n-m);i++){
        if(phash==thash){
            int j;
            for(j=0;j<m;j++){
                if(T[i+j]!=P[j])
                    break;
            }
            if(j==m)
                cout<<"Match found at "<<i<<endl;
            else
                ++spurious_hits;
        }
        
        if (i < (n - m)) {
            thash=update_hash(thash,T[i],T[i+m],q,m);
        }
    }

    cout<<"Spurious hits = "<<spurious_hits<<endl;
}

int main(){
    int q;
    string T,P;
    cout<<"Enter the modulus of hash function : \n";
    cin>>q;
    cout<<"Enter the text string :\n";
    cin>>T;
    cout<<"Enter the pattern to be searched :\n";
    cin>>P;

    rabin_karp(T,P,q);
}

