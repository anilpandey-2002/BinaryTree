int height(Node *node)
{
    if (!node)
        return 0;
    int lHeight = height(node->left), rHeight = height(node->right);
    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

void getCurrentLevel(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;
    if (level == 1)
        ans.push_back(root->data);
    else
    {
        getCurrentLevel(root->left, level - 1, ans);
        getCurrentLevel(root->right, level - 1, ans);
    }
}

void levelOrderTraversal(Node *root, vector<int> &ans)
{
    for (int i = height(root); i >= 1; i--)
        getCurrentLevel(root, i, ans);
}

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    levelOrderTraversal(root, ans);
    return ans;
}
