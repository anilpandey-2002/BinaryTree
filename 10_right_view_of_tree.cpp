#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int item) : data(item), left(nullptr), right(nullptr) {}
};

void rightViewUtil(Node *root, int level, int *max_level)
{
    if (!root)
        return;
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

void rightView(Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    rightView(root);
    return 0;
}
