#include <iostream>
 
// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class MinHeap {
private:
    Node* root; // Pointer to the root of the binary tree

    // Helper function to perform heapify operation
    void heapify(Node* root) {
        if (root == nullptr) {
            return;
        }

        Node* smallest = root;
        Node* left = root->left;
        Node* right = root->right;

        // Find the smallest among root, left child, and right child
        if (left != nullptr && left->data < smallest->data) {
            smallest = left;
        }
        if (right != nullptr && right->data < smallest->data) {
            smallest = right;
        }

        // If the smallest is not the root, swap and recursively heapify
        if (smallest != root) {
            std::swap(root->data, smallest->data);
            heapify(smallest);
        }
    }

public:
    MinHeap() : root(nullptr) {}

    // Function to insert a new node into the heap
    void insert(int value) {
        root = insertHelper(root, value);
    }

    // Helper function for inserting a new node
    Node* insertHelper(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertHelper(root->left, value);
        } else {
            root->right = insertHelper(root->right, value);
        }

        // Heapify to maintain the min heap property
        heapify(root);

        return root;
    }

    // Function to remove and retrieve the top-most element of the heap
    int removeTop() {
        if (root == nullptr) {
            std::cerr << "Heap is empty. Cannot remove top element.\n";
            return -1; // Return a placeholder value indicating an error
        }

        int topValue = root->data;

        // Replace the root with the rightmost leaf, and then heapify
        Node* rightmostLeafParent = nullptr;
        Node* rightmostLeaf = findRightmostLeaf(root, rightmostLeafParent);

        if (rightmostLeafParent == nullptr) {
            // The tree has only one node
            delete root;
            root = nullptr;
        } else {
            root->data = rightmostLeaf->data;
            if (rightmostLeafParent->left == rightmostLeaf) {
                delete rightmostLeafParent->left;
                rightmostLeafParent->left = nullptr;
            } else {
                delete rightmostLeafParent->right;
                rightmostLeafParent->right = nullptr;
            }

            // Heapify to maintain the min heap property
            heapify(root);
        }

        return topValue;
    }

    // Function to retrieve the top-most element of the heap without removing it
    int getTop() const {
        if (root == nullptr) {
            std::cerr << "Heap is empty. Cannot retrieve top element.\n";
            return -1; // Return a placeholder value indicating an error
        }

        return root->data;
    }

    // Helper function to find the rightmost leaf in the binary tree
    Node* findRightmostLeaf(Node* root, Node*& parent) {
        Node* current = root;
        parent = nullptr;

        while (current->right != nullptr) {
            parent = current;
            current = current->right;
        }

        return current;
    }
};

int main() {
    MinHeap minHeap;

    // Insert elements into the heap
    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(5);
    minHeap.insert(1);

    // Print the top element
    std::cout << "Top element: " << minHeap.getTop() << "\n";

    // Remove and print the top element
    int removedValue = minHeap.removeTop();
    std::cout << "Removed top element: " << removedValue << "\n";

    // Print the top element after removal
    std::cout << "Top element after removal: " << minHeap.getTop() << "\n";

    return 0;
}
