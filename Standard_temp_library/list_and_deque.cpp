#include <bits/stdc++.h>
using namespace std;

int main(){
    // list in stdlib is implemented as a doubly linked list.
    list <int> ls;
    ls.push_back(20);
    ls.emplace_back(25);
    
    ls.push_front(10);
    ls.emplace_front(5);

    for(auto it : ls)
        cout<<it<<" ";

    ls.front();//returns a read-only reference to the front
    ls.back();//returns a read-only reference at the back
    ls.pop_front();
    ls.pop_back();

    //  more functions like clear, empty , iterator- begin,end ,insert,swap,size

    deque <string> dq; // double ended queue- same functions as list data structure
    dq.push_back("alpha");
    dq.push_front("gamma");

}