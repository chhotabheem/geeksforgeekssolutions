struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void mirror(Node *node)
{
    if (!node || (!node->left && !node->right))
    {
        return;
    }
    Node *temp = node->right;
    node->right = node->left;
    node->left = temp;
    mirror(node->left);
    mirror(node->right);
}