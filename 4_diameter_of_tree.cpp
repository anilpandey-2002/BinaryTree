int height(Node *node)
{
    if (!node)
        return 0;
    int lHeight = height(node->left), rHeight = height(node->right);
    return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
}

int diameter(Node *root)
{
    if (!root)
        return 0;
    queue<Node *> q;
    q.push(root);
    int mx = INT_MIN;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int lh = height(temp->left), rh = height(temp->right);
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        mx = max(mx, lh + rh + 1);
    }
    return mx;
}
