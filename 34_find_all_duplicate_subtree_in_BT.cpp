#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

string inorder(Node *node, unordered_map<string, int> &m)
{
    if (!node)
        return "";

    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";

    if (m[str] == 1)
        cout << node->data << " ";

    m[str]++;

    return str;
}

void printAllDups(Node *root)
{
    unordered_map<string, int> m;
    inorder(root, m);
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver code
int main()
{
    Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(2);
    root->right->left->left = newNode(4);
    root->right->right = newNode(4);
    printAllDups(root);
    return 0;
}
