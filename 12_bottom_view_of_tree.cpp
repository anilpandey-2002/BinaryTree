void printBottomViewUtil(Node *root, int curr, int hd, map<int, pair<int, int>> &m)
{
    if (!root)
        return;
    if (m.find(hd) == m.end() || m[hd].second <= curr)
        m[hd] = make_pair(root->data, curr);
    printBottomViewUtil(root->left, curr + 1, hd - 1, m);
    printBottomViewUtil(root->right, curr + 1, hd + 1, m);
}

void printBottomView(Node *root)
{
    map<int, pair<int, int>> m;
    printBottomViewUtil(root, 0, 0, m);
    for (auto &p : m)
        cout << p.second.first << " ";
}
