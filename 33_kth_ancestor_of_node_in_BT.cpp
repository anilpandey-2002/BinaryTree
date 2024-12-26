#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void generateArray(Node *root, int ancestors[])
{
    ancestors[root->data] = -1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left)
        {
            ancestors[temp->left->data] = temp->data;
            q.push(temp->left);
        }
        if (temp->right)
        {
            ancestors[temp->right->data] = temp->data;
            q.push(temp->right);
        }
    }
}

int kthAncestor(Node *root, int n, int k, int node)
{
    int ancestors[n + 1] = {0};
    generateArray(root, ancestors);
    int count = 0;
    while (node != -1)
    {
        node = ancestors[node];
        count++;
        if (count == k)
            break;
    }
    return node;
}

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 2, node = 5;
    cout << kthAncestor(root, 5, k, node);
    return 0;
}
