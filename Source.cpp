#include <iostream>
using namespace std;

// Define the structure of the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in the tree
Node* searchNode(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return searchNode(root->right, data);
    }
    return searchNode(root->left, data);
}

// Function to print the inorder traversal of the tree
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Main function to test the binary search tree
int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    inorderTraversal(root);
    Node* searchedNode = searchNode(root, 40);
    if (searchedNode == NULL) {
        cout << "\nNode not found";
    }
    else {
        cout << "\nNode found: " << searchedNode->data;
    }
    return 0;
}
