#include <bits/stdc++.h>
using namespace std;

int main(){
    //vector is a container mostly used when we are not familiar with the size of data structure.
    vector <int> vec;
    vec.push_back(20);
    vec.emplace_back(30);//faster insertion but increased size

    vector <pair<int,int>> vec2;
    vec2.emplace_back(20,30);
    // cout<<vec2[0].first;

    vector <int> v(5);//initialises 5 elements in vector with 0.Can be used to initialise matrices etc.
    // for(int i=0;i<5;i++)
    //     cout<<v[i]<<" ";
    vector <int> v1(5,21);
    // for(int i=0;i<5;i++)
    //     cout<<v1[i]<<" ";

    vector <int> v2(v1);//copying a vector
    // for(int i=0;i<5;i++)
    //     cout<<v2[i]<<" ";
    
    //writing iterator 
    vector <int> :: iterator it = v1.begin(); //iterator is a pointer pointing to a memory location of element in memory.
    // cout<<*(it); // to access value, we use *it

    vector <int> :: iterator it1 = v1.end();
    // vector <int> :: iterator it1 = v1.rend();
    // vector <int> :: iterator it1 = v1.rbegin();

    // for(auto it = v1.begin();it!=v1.end();it++)
    //     cout<<*it<<" ";
    // for(auto it:v)
    // cout<<it;
    int n;
    vector <vector<int>> graph ;
    // for(int i=0;i<5;i++){
    //     vector<int> sub;
    //     cout<<"new vector"<<endl;
    //     for(int j=0;j<5;j++){
    //         cout<<"Enter data : \n";
    //         cin>> n;
    //         if(n==-1) break;
    //         sub.push_back(n);
    //     }
    //     graph.push_back(sub);
    // }
    // for(auto it : graph){
    //     for(auto it2 : it){
    //         cout<<it2<<" ";
    //     }
    //     cout<<endl;
    // }

    /*deletion in a vector :  ways to erase
    1-give location of individual element
    2-give location of starting and ending locations to delete multiple elements
    */

   vector <string> names ={"ali","anmol","anika","ammar","adnaan","ayaan"};
   vector <string>::iterator str=names.begin();
   names.erase(names.begin());
   cout<<*str<<endl;
   names.erase(names.end()-2,names.end());
   for(auto str1:names){
    cout<<str1;
   }

   /*
    v.size() - gives no of elements in vec
    v.pop_back() - removes and returns last element
    v.clear()- clears entire vector
    v1.swap(v2)- swaps two vectors v1 and v2    
   */

}
