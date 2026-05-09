#include <iostream>
using namespace std;

// Structure of Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
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

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    return 0;
}