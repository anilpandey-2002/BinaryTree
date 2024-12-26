void topView()
{
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    int hd = 0, l = 0, r = 0;
    stack<int> left;
    vector<int> right;
    Node *node;

    while (!q.empty())
    {
        node = q.front().first;
        hd = q.front().second;
        if (hd < l)
        {
            left.push(node->data);
            l = hd;
        }
        else if (hd > r)
        {
            right.push_back(node->data);
            r = hd;
        }
        if (node->left)
            q.push(make_pair(node->left, hd - 1));
        if (node->right)
            q.push(make_pair(node->right, hd + 1));
        q.pop();
    }

    while (!left.empty())
    {
        cout << left.top() << " ";
        left.pop();
    }

    cout << root->data << " ";

    for (auto x : right)
    {
        cout << x << " ";
    }
}
