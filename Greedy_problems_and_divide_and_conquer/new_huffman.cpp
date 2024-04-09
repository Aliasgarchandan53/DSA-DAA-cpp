/*
    1- an unordered map stores characters and corresponding frequencies and sends it to huffman function.
    2- node structure defines node of a huffman tree
    3- a custom magnetic comparator is used to compare nodes in the priority queue .
*/

#include <bits/stdc++.h>
using namespace std;

// Node of huffman tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int f)
    {
        this->ch = ch;
        this->freq = f;
        left = right = nullptr;
    }
};

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(Node *root, string code)
{
    if (root == nullptr)
        return;
    if (root->ch != '\0')
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void Huffman_encoding(unordered_map<char, int> frequency)
{

    // initialization
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    Node *left, *right, *newTop;

    // filling the pq :
    for (auto &it : frequency)
    {
        minHeap.push(new Node(it.first, it.second));
    }

    // building the huffman tree
    while (minHeap.size() > 1)
    {

        // extract top 2 elements
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        newTop = new Node('\0', (left->freq + right->freq));
        newTop->left = left;
        newTop->right = right;

        minHeap.push(newTop);
    }

    printCodes(minHeap.top(), "");
}

int main()
{
    unordered_map<char, int> frequency;
    int n;
    cout << "Enter number of charcaters :\n";
    cin >> n;
    int f;
    char c;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the character and frequency : ";
        cin >> c >> f;
        frequency[c] = f;
    }
    Huffman_encoding(frequency);
    return 0;
}