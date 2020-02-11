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
struct BalanceHeightInfo
{
    int height;
    bool is_balanced;
};

BalanceHeightInfo is_tree_balanced(Node *root)
{
    if (!root)
    {
        return {-1, true};
    }
    auto left_bal_ht_info = is_tree_balanced(root->left);
    if (!left_bal_ht_info.is_balanced)
    {
        return {0, false};
    }
    auto right_bal_ht_info = is_tree_balanced(root->right);
    if (!right_bal_ht_info.is_balanced)
    {
        return {0, false};
    }
    BalanceHeightInfo node_bal_ht_info;
    node_bal_ht_info.is_balanced = abs(left_bal_ht_info.height - right_bal_ht_info.height) <= 1;
    node_bal_ht_info.height = std::max(left_bal_ht_info.height, right_bal_ht_info.height) + 1;
    return node_bal_ht_info;
}

bool isBalanced(Node *root)
{
    auto bal_ht_info = is_tree_balanced(root);
    return bal_ht_info.is_balanced;
}