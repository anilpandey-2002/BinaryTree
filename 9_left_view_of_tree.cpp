#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int item) : data(item), left(nullptr), right(nullptr) {}
};

void leftViewUtil(Node *root, int level, int *max_level)
{
    if (!root)
        return;
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
}

void leftView(Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(15);
    root->right->right->left = new Node(14);

    leftView(root);
    return 0;
}
