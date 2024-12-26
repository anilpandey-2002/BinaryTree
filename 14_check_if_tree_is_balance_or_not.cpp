int height(Node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void check(Node *root, bool &balanced)
{
    if (!root || !balanced)
        return;
    if (abs(height(root->left) - height(root->right)) > 1)
    {
        balanced = false;
        return;
    }
    check(root->left, balanced);
    check(root->right, balanced);
}

bool isBalanced(Node *root)
{
    bool balanced = true;
    check(root, balanced);
    return balanced;
}
