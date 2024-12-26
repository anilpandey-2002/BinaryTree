unordered_map<string, int> m;
string recur(Node *root)
{
    if (!root)
        return "$";
    string s = to_string(root->data);
    if (root->left)
        s += recur(root->left);
    if (root->right)
        s += recur(root->right);
    m[s]++;
    return s;
}
bool dupSub(Node *root)
{
    m.clear();
    recur(root);
    for (auto i : m)
        if (i.second >= 2)
            return true;
    return false;
}

unordered_set<string> s;
string recur(Node *root, bool &ans)
{
    if (!root)
        return "$";
    string str = to_string(root->data);
    if (root->left)
        str += recur(root->left, ans);
    if (root->right)
        str += recur(root->right, ans);
    if (s.find(str) != s.end())
        ans = true;
    s.insert(str);
    return str;
}
bool dupSub(Node *root)
{
    s.clear();
    bool ans = false;
    recur(root, ans);
    return ans;
}

const char MARKER = '$';
unordered_set<string> subtrees;
string dupSubUtil(Node *root)
{
    if (!root)
        return MARKER;
    string lStr = dupSubUtil(root->left);
    if (lStr == "")
        return "";
    string rStr = dupSubUtil(root->right);
    if (rStr == "")
        return "";
    string s = to_string(root->data) + lStr + rStr;
    if ((rStr != "$" || lStr != "$") && subtrees.find(s) != subtrees.end())
        return "";
    subtrees.insert(s);
    return s;
}
bool dupSub(Node *root)
{
    subtrees.clear();
    return dupSubUtil(root) == "";
}
