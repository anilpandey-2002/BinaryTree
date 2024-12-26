int findIndex(int arr[], int start, int target)
{
    int i = 0;
    while (arr[start + i] != target)
        i++;
    return i;
}

Node *buildUtil(int inorder[], int preorder[], int inStart, int preStart, int n)
{
    if (n == 0)
        return NULL;
    Node *ret = new Node(preorder[preStart]);
    int i = findIndex(inorder, inStart, preorder[preStart]);
    ret->left = buildUtil(inorder, preorder, inStart, preStart + 1, i);
    ret->right = buildUtil(inorder, preorder, inStart + i + 1, preStart + i + 1, n - i - 1);
    return ret;
}

Node *buildTree(int inorder[], int preorder[], int n)
{
    return buildUtil(inorder, preorder, 0, 0, n);
}

class node
{
public:
    char data;
    node *left;
    node *right;
};

int search(char arr[], int strt, int end, char value)
{
    int i;
    for (i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
}

node *newNode(char data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

node *buildTree(char in[], char pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
    if (inStrt > inEnd)
        return NULL;
    node *tNode = newNode(pre[preIndex++]);
    if (inStrt == inEnd)
        return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode->data);
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}

void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);
    node *root = buildTree(in, pre, 0, len - 1);
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}
