int sum(struct node *root)
{
    if (root == NULL)
        return 0;
    return sum(root->left) + root->data + sum(root->right);
}

int isSumTree(struct node *node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 1;
    int ls = sum(node->left), rs = sum(node->right);
    if ((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
        return 1;
    return 0;
}
