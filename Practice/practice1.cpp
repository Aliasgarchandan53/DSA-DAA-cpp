/* Huffman encoding:
    1- node structure
    2- functor - function structure for comparison
    3- huffman encoding function -  uses minheap
    4- get code words function (recursive)
    5- print code words function 
*/
#include <bits/stdc++.h>
using namespace std;

//structures and functors :
struct Node{
    char data;
    int freq;
    Node *left,*right;

    Node(char data,int freq){
        this->data=data;
        this->freq=freq;
        right=left=nullptr;
    }
};

struct compare{
    bool operator()(Node *l,Node *r){
        return(l->freq > r->freq);
    }
};

void printCodes(Node *root, string code){

    if(root==nullptr)//when end of leaf is reached
        return;

    if(root->data!='$'){    //when leaf is reached
        cout<<root->data<<": "<<code<<endl;
        return;    
    }
    
    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
    
}

void Huffman_Encoding(unordered_map<char,int> &frequencies){
    //initialising required nodes and pq:
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    Node *left,*right,*newTop;

    //filling the minHeap:
    for(const auto entry:frequencies){
        minHeap.push(new Node(entry.first,entry.second));
    }

    //building huffman tree
    while(minHeap.size()!=1){
        left= minHeap.top();
        minHeap.pop();
        right=minHeap.top();
        minHeap.pop();

        newTop = new Node('$',(left->freq + right->freq));
        newTop->left=left;
        newTop->right=right;

        minHeap.push(newTop);
    }
    //get and print codes:
    printCodes(minHeap.top(),"");
}

int main(){
    int n,freq; char ch;
    cout<<"Enter the number of characters to be encoded :\n";
    cin>>n;
    unordered_map<char,int> frequencies;
    for(int i=0;i<5;i++){
        cout<<"Enter the character and its corresponding frequency :\n";
        cin>>ch>>freq;
        frequencies[ch]=freq;
    }
    Huffman_Encoding(frequencies);
    return 0;
}