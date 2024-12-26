void recur(Node *root, int level, int &maxLevel, int sum, int &ans)
{
    if (!root)
        return;
    sum += root->data;
    if (level >= maxLevel)
    {
        maxLevel = level;
        ans = sum;
    }
    recur(root->left, level + 1, maxLevel, sum, ans);
    recur(root->right, level + 1, maxLevel, sum, ans);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int ans = 0, maxLevel = 0;
    recur(root, 0, maxLevel, 0, ans);
    return ans;
}
