#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

node *bintree2listUtil(node *root)
{
    if (root == NULL)
        return root;
    if (root->left != NULL)
    {
        node *left = bintree2listUtil(root->left);
        while (left->right != NULL)
            left = left->right;
        left->right = root;
        root->left = left;
    }
    if (root->right != NULL)
    {
        node *right = bintree2listUtil(root->right);
        while (right->left != NULL)
            right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}

node *bintree2list(node *root)
{
    if (root == NULL)
        return root;
    root = bintree2listUtil(root);
    while (root->left != NULL)
        root = root->left;
    return root;
}

node *newNode(int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

int main()
{
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    node *head = bintree2list(root);
    printList(head);
    return 0;
}
