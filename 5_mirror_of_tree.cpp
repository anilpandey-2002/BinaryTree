#include <iostream>
using namespace std;

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
} node;

node *createNode(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

node *mirrorTree(node *root)
{
    if (!root)
        return root;
    swap(root->left, root->right);
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
    return root;
}

int main()
{
    node *tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);

    printf("Inorder of original tree: ");
    inorder(tree);
    mirrorTree(tree);
    printf("\nInorder of Mirror tree: ");
    inorder(tree);

    return 0;
}
