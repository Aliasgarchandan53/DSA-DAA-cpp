#include <iostream>
#include <string>
using namespace std;

class KMP{
    
    public:
    int m , n;
    string txt,pat;
    int* LPS_table;

    KMP(string txt , string pat){
        this->txt=txt;
        this->pat=pat;
        n=txt.length();
        m=pat.length();
        LPS_table = new int[m];
        for(int i=0;i<m;i++)
            LPS_table[i]=0;
    }

    void compute_lps(){
        int len = 0 , i=1;
        while(i<m){
            if(pat[i]==pat[len]){
                LPS_table[i]=(++len);
                i++;
            }
            else{
                if(len !=0)
                    len=LPS_table[len-1];
                else{
                    LPS_table[i++]=0;
                }
            }
        }
    }
    void KMP_Matcher(){
        compute_lps();
        int i=0,j=0;
        while(i<n){
            if(txt[i]==pat[j]){
                i++;j++;
            }
            else{
                if(j!=0) j=LPS_table[j-1];
                else i++;
            }
            if(j==m){
                cout<<"Match found at "<<(i-j)<<endl;
                j=LPS_table[j-1];
            }
        }

    }

};


int main(){
    KMP k("aaaabaaaaabbbaaaab","aaab");
    k.KMP_Matcher();
    return 0;
}