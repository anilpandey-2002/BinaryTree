bool checkUtil(struct Node *root, int level, int *leafLevel)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
    {
        if (*leafLevel == 0)
        {
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }
    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}

int checkLevelLeafNode(Node *root)
{
    if (!root)
        return 1;
    queue<Node *> q;
    q.push(root);
    int result = INT_MAX, level = 0;
    while (!q.empty())
    {
        int size = q.size();
        level++;
        while (size--)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
                if (!temp->left->right && !temp->left->left)
                {
                    if (result == INT_MAX)
                        result = level;
                    else if (result != level)
                        return 0;
                }
            }
            if (temp->right)
            {
                q.push(temp->right);
                if (!temp->right->left && !temp->right->right)
                {
                    if (result == INT_MAX)
                        result = level;
                    else if (result != level)
                        return 0;
                }
            }
        }
    }
    return 1;
}
