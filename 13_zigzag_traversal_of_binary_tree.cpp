vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    int level = 1;

    while (!q.empty())
    {
        stack<Node *> s;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            ans.push_back(curr->data);
            if (level % 2)
            {
                if (curr->left)
                    s.push(curr->left);
                if (curr->right)
                    s.push(curr->right);
            }
            else
            {
                if (curr->right)
                    s.push(curr->right);
                if (curr->left)
                    s.push(curr->left);
            }
            q.pop();
        }
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
        level++;
    }
    return ans;
}
