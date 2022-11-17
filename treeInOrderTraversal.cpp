#include <iostream>

// Tree node structure
class Node
{
public:
    int data;    // data in the node
    Node *left;  // a pointer to the left node
    Node *right; // a pointer to the right node
    Node(int d)  // node constructor
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        std::cout << root->data << " ";
        inOrder(root->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(6);
    root->right->right->left->right = new Node(4);

    inOrder(root);

    return 0;
}