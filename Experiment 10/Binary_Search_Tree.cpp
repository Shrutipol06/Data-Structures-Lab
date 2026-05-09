#include <iostream>
using namespace std;

// Structure of BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create New Node
Node* createNode(int val) {

    Node* newNode = new Node;

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert Node in BST
Node* insert(Node* root, int val) {

    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);

    else
        root->right = insert(root->right, val);

    return root;
}

// Inorder Traversal
void inorder(Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root) {

    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root) {

    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Main Function
int main() {

    Node* root = NULL;

    // Insert Elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}