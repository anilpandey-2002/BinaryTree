
vector<vector<int>> result;
void diagonalPrint(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        vector<int> answer;

        while (size--)
        {
            Node *temp = q.front();
            q.pop();

            while (temp)
            {
                answer.push_back(temp->data);

                if (temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
        result.push_back(answer);
    }
}