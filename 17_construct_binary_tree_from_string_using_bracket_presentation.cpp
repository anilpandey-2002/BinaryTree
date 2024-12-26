#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

void preOrder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int findIndex(const string &str, int si, int ei)
{
    if (si > ei)
        return -1;

    stack<char> s;
    for (int i = si; i <= ei; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')')
        {
            s.pop();
            if (s.empty())
                return i;
        }
    }
    return -1;
}

Node *treeFromString(const string &str, int si, int ei)
{
    if (si > ei)
        return nullptr;

    Node *root = newNode(str[si] - '0'); // Convert char to int
    int index = -1;

    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);

    if (index != -1)
    {
        root->left = treeFromString(str, si + 2, index - 1);
        root->right = treeFromString(str, index + 2, ei - 1);
    }

    return root;
}

int main()
{
    string str = "4(2(3)(1))(6(5))";
    Node *root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
    return 0;
}
