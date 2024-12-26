int sum(Node *node)
{
    if (node == NULL)
        return 0;
    int currData = node->data;
    int lSum = sum(node->left);
    int rSum = sum(node->right);
    node->data = lSum + rSum;
    return node->data + currData;
}

void toSumTree(Node *node)
{
    sum(node);
}
