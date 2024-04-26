/* Huffman Encoding :
1 functions : huffman encoding-builds tree, print code words recursively
2 data structures : a struct node for tree , minheap for tree, 
    custom comparator to build minheap according to frequencies of node
    unordered map to insert characters and corresponding frequencies
*/

#include <bits/stdc++.h>
using namespace std;

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
        return (l->freq > r->freq);
    }
};

void printCodes(Node*root,string code){
    if(root==nullptr)
        return;
    if(root->data!='$')
        cout<<root->data<<" : "<<code<<endl;
    printCodes(root->left,code+"0");
    printCodes(root->right,code+"1");
}


void printTree(Node*root,bool left){
    if(root==nullptr)
        return;
    if(left)
        cout<<root->data<<"\t"<<endl;
    else
        cout<<"\t"<<root->data<<endl;
    printTree(root->left,true);
    printTree(root->right,false);
}

void Huffman_encoding(unordered_map<char,int> &frequencies){
    //initialise Priority queue
    priority_queue<Node*,vector<Node*>,compare> minheap;
    for(auto entry:frequencies){
        minheap.push(new Node(entry.first,entry.second));
    }

    while(minheap.size()!=1){
        Node *left =minheap.top();
        minheap.pop();

        Node *right =minheap.top();
        minheap.pop();

        Node *root=new Node('$',(left->freq + right->freq)) ; //new root node
        root->left =left;
        root->right=right;
        minheap.push(root);
    } 
    //printing code words :
    cout<<"Code words are :\n";
    printCodes(minheap.top(),"");
    cout<<"Tree :\n";
    printTree(minheap.top(),false);
}
int main(){
    unordered_map<char,int> frequencies;
    int n,freq;char ch;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ch>>freq;
        frequencies.insert({ch,freq});
    }
    Huffman_encoding(frequencies);
    return 0;
}