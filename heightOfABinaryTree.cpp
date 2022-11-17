#include <iostream>

// Tree Node Structure
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

int maxVal(int v1, int v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
}

/*Note: When writing a recursive function, suppose your function will give you correct result.
    Recursive function are defined in terms of themselves.
    For example to find the height of the tree, you need the height of the left subtree and right subtree.
    Then you take the biggest one and add 1 edge from the root of the tree to the root of that subtree.
    How can we find the height of left and right subtrees ?. Answer: Calling our height(root) on the left and right subtrees respectively.
    As you can see, that's where a function calls itself on the smaller subinstance(s) of the original problem
    to find the answer to original problem.
*/

int height(Node *root)
{
    /*base case- It might not seem logical at first, but it really is.
     In fact, we might have considered the base case as when there is only one node
     but that would overcomplicate our work
    */
    if (root == NULL)
        return -1; // why -1 ? just observation (I know zero is logical here)

    // the height of the left subtree
    int left_subtree_height = height(root->left);
    // the height of the right subtree
    int right_subtree_height = height(root->right);
    // take the biggest one and add 1 to that
    return maxVal(left_subtree_height, right_subtree_height) + 1;
}

int main()
{
    Node *root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(6);
    root->right->right->left->right = new Node(4);

    std::cout << height(root); // 4

    return 0;
}
