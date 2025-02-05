#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

Node *newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

bool findPath(Node *root, vector<int> &path, int k)
{
    if (!root)
        return false;
    path.push_back(root->key);
    if (root->key == k)
        return true;
    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;
    path.pop_back();
    return false;
}

int findLCA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i])
        i++;
    return path1[i - 1];
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << "\n";
    cout << "LCA(4, 6) = " << findLCA(root, 4, 6) << "\n";
    cout << "LCA(3, 4) = " << findLCA(root, 3, 4) << "\n";
    cout << "LCA(2, 4) = " << findLCA(root, 2, 4) << "\n";
    return 0;
}
