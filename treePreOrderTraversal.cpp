#include <iostream>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
/**********************
 * in preorder traversal you travers parent node first and then the left subtree and right subtree
 * This is one of three ways you can run Depth-First Search on a binary tree
 ***********************/

void preOrder(Node *root)
{
    if (root)
    {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
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

    preOrder(root);

    return 0;
}