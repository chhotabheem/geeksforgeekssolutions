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

#include <algorithm>

int height(Node *node)
{
    if (!node)
    {
        return 0;
    }
    return (std::max(height(node->left), height(node->right)) + 1);
}

int diameter(Node *node)
{
    if (!node)
    {
        return 0;
    }
    int left_height = height(node->left);
    int right_height = height(node->right);
    int left_dia = diameter(node->left);
    int right_dia = diameter(node->right);
    int max_height = height(node);
    return (std::max(std::max(left_dia, right_dia), left_height + right_height + 1));
}
