#include <bits/stdc++.h>
using namespace std;

int main(){
    //stack LIFO
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.top();
    st.pop();
    cout<<st.top()<<endl;

    // queue FIFO
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;

    // max and min heaps
    priority_queue <int> pq; //by default cpp maintains pq in form of a max heap
    int m=0;
    // while(m!=-1){
    //     cout<<"Enter elements in pq : -1 to stop";
    //     cin>>m;
    //     pq.push(m);
    // }
    // for(int i=0;i<pq.size();i++){
    //     cout<<pq.top()<<endl;
    //     pq.pop();
    // }

    priority_queue <int , vector<int>,greater<int>> pq2;
    while(m!=-1){
        cout<<"Enter elements in pq : -1 to stop";
        cin>>m;
        pq2.push(m);
    }
    for(int i=0;i<pq2.size();i++){
        cout<<pq2.top()<<endl;
        pq2.pop();
    }
    return 0;
}