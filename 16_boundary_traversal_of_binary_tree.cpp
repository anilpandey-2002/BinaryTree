struct Node
{
    int data;
    Node *left, *right;
};

void printLeaves(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    printLeaves(root->left, ans);
    if (!(root->left) && !(root->right))
        ans.push_back(root->data);
    printLeaves(root->right, ans);
}

void printBoundaryLeft(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        ans.push_back(root->data);
        printBoundaryLeft(root->left, ans);
    }
    else if (root->right)
    {
        ans.push_back(root->data);
        printBoundaryLeft(root->right, ans);
    }
}

void printBoundaryRight(Node *root, vector<int> &dummy)
{
    if (root == NULL)
        return;
    if (root->right)
    {
        printBoundaryRight(root->right, dummy);
        dummy.push_back(root->data);
    }
    else if (root->left)
    {
        printBoundaryRight(root->left, dummy);
        dummy.push_back(root->data);
    }
}

vector<int> printBoundary(Node *root)
{
    if (root == NULL)
        return {};
    vector<int> ans;
    ans.push_back(root->data);
    printBoundaryLeft(root->left, ans);
    printLeaves(root, ans);
    vector<int> dummy;
    printBoundaryRight(root->right, dummy);
    ans.insert(ans.end(), dummy.rbegin(), dummy.rend());
    return ans;
}

Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    Node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    vector<int> boundary = printBoundary(root);
    for (int i : boundary)
        cout << i << " ";
    return 0;
}
