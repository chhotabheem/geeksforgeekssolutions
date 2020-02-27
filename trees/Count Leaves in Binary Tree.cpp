struct Node
{
    int data;
    Node *left;
    Node *right;
};

void countLeaves(Node *root, int &count)
{
    if (!root)
    {
        return;
    }
    if (!root->left && !root->right)
    {
        ++count;
        return;
    }
    countLeaves(root->left, count);
    countLeaves(root->right, count);
}

int countLeaves(Node *root)
{
    int count = 0;
    countLeaves(root, count);
    return count;
}
