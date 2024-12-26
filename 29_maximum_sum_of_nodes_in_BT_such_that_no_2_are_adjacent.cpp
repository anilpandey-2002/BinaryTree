#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int sumOfGrandChildren(node *n, map<node *, int> &mp)
{
    int sum = 0;
    if (n->left)
        sum += getMaxSumUtil(n->left->left, mp) + getMaxSumUtil(n->left->right, mp);
    if (n->right)
        sum += getMaxSumUtil(n->right->left, mp) + getMaxSumUtil(n->right->right, mp);
    return sum;
}

int getMaxSumUtil(node *n, map<node *, int> &mp)
{
    if (!n)
        return 0;
    if (mp.find(n) != mp.end())
        return mp[n];
    int incl = n->data + sumOfGrandChildren(n, mp);
    int excl = getMaxSumUtil(n->left, mp) + getMaxSumUtil(n->right, mp);
    return mp[n] = max(incl, excl);
}

int getMaxSum(node *n)
{
    return n ? getMaxSumUtil(n, {}) : 0;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);
    cout << getMaxSum(root) << endl;
    return 0;
}
