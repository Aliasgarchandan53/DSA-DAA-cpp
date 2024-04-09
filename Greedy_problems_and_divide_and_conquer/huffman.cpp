 #include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;
// Node structure for the Huffman tree
struct Node {
    char data; // Alphabet character
    int frequency; // Frequency of the character
    Node* left;
    Node* right;

    Node(char ch, int freq) : data(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for the min heap based on frequency
struct CompareNodes {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return (lhs->frequency > rhs->frequency);
    }
};

class HuffmanCoding {
public:
    Node* root; // Root of the Huffman tree
    unordered_map<char, string> codewords; // Codewords for each alphabet

    // Function to build the Huffman tree from given frequencies
    void buildTree(const unordered_map<char, int>& frequencies) {
        priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

        // Create a leaf node for each character and push it into the min heap
        for (const auto& entry : frequencies) {
            minHeap.push(new Node(entry.first, entry.second));
        }           

        // Build the Huffman tree by repeatedly combining two nodes with the lowest frequencies
        while (minHeap.size() > 1) {
            Node* left = minHeap.top();
            minHeap.pop();

            Node* right = minHeap.top();
            minHeap.pop();

            Node* combinedNode = new Node('\0', left->frequency + right->frequency);
            combinedNode->left = left;
            combinedNode->right = right;

            minHeap.push(combinedNode);
        }

        // The remaining node in the min heap is the root of the Huffman tree
        root = minHeap.top();
    }

    // Function to generate codewords for each alphabet in the Huffman tree
    void generateCodewords(Node* node, const string& currentCode) {
        if (node == nullptr) {
            return;
        }

        if (node->data != '\0') {
            codewords[node->data] = currentCode;
        }

        generateCodewords(node->left, currentCode + "0");
        generateCodewords(node->right, currentCode + "1");
    }

public:
    HuffmanCoding(const unordered_map<char, int>& frequencies) : root(nullptr) {
        buildTree(frequencies);
        generateCodewords(root, "");
    }

    // Function to print the Huffman tree and codewords for each alphabet
    void printTreeAndCodewords() const {
        cout << "Huffman Tree:\n";
        printTree(root, 0);

        cout << "\nCodewords for each alphabet:\n";
        for (const auto& entry : codewords) {
            cout << "'" << entry.first << "': " << entry.second << "\n";
        }
    }

    // Recursive function to print the Huffman tree
    void printTree(Node* node, int indent) const {
        if (node == nullptr) {
            return;
        }

        printTree(node->right, indent + 4);

        for (int i = 0; i < indent; ++i) {
            cout << " ";
        }

        if (node->data == '\0') {
            cout << "Freq: " << node->frequency << "\n";
        } else {
            cout << node->data << "\n";
        }

        printTree(node->left, indent + 4);
    }
};

int main() {
    unordered_map<char, int> frequencies;
    int numCharacters;

    cout << "Enter the number of characters: ";
    cin >> numCharacters;

    for (int i = 0; i < numCharacters; ++i) {
        char ch;
        int freq;

        cout << "Enter character and frequency (separated by space): ";
        cin >> ch >> freq;

        frequencies[ch] = freq;
    }

    HuffmanCoding huffman(frequencies);

    // Print the Huffman tree and codewords
    huffman.printTreeAndCodewords();

    return 0;
}

/*

// C++(STL) program for Huffman Coding with STL 
#include <bits/stdc++.h> 
using namespace std; 

// A Huffman tree node 
struct MinHeapNode { 

	// One of the input characters 
	char data; 

	// Frequency of the character 
	unsigned freq; 

	// Left and right child 
	MinHeapNode *left, *right; 

	MinHeapNode(char data, unsigned freq) 

	{ 

		left = right = NULL; 
		this->data = data; 
		this->freq = freq; 
	} 
}; 

// For comparison of 
// two heap nodes (needed in min heap) 
struct compare { 

	bool operator()(MinHeapNode* l, MinHeapNode* r) 

	{ 
		return (l->freq > r->freq); 
	} 
}; 

// Prints huffman codes from 
// the root of Huffman Tree. 
void printCodes(struct MinHeapNode* root, string str) 
{ 

	if (!root) 
		return; 

	if (root->data != '$') 
		cout << root->data << ": " << str << "\n"; 

	printCodes(root->left, str + "0"); 
	printCodes(root->right, str + "1"); 
} 

// The main function that builds a Huffman Tree and 
// print codes by traversing the built Huffman Tree 
void HuffmanCodes(char data[], int freq[], int size)  
{ 
	struct MinHeapNode *left, *right, *top; 

	// Create a min heap & inserts all characters of data[] 
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, 
				compare> 
		minHeap; 

	for (int i = 0; i < size; ++i) 
		minHeap.push(new MinHeapNode(data[i], freq[i])); 

	// Iterate while size of heap doesn't become 1 
	while (minHeap.size() != 1) { 

		// Extract the two minimum 
		// freq items from min heap 
		left = minHeap.top(); 
		minHeap.pop(); 

		right = minHeap.top(); 
		minHeap.pop(); 

		// Create a new internal node with 
		// frequency equal to the sum of the 
		// two nodes frequencies. Make the 
		// two extracted node as left and right children 
		// of this new node. Add this node 
		// to the min heap '$' is a special value 
		// for internal nodes, not used 
		top = new MinHeapNode('$', 
							left->freq + right->freq); 

		top->left = left; 
		top->right = right; 

		minHeap.push(top); 
	} 

	// Print Huffman codes using 
	// the Huffman tree built above 
	printCodes(minHeap.top(), ""); 
} 

// Driver Code 
int main() 
{ 

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
	int freq[] = { 5, 9, 12, 13, 16, 45 }; 

	int size = sizeof(arr) / sizeof(arr[0]); 

	HuffmanCodes(arr, freq, size); 

	return 0; 
} 

// This code is contributed by Aditya Goel
*/