struct Node
{
    int data;
    Node *left, *right;
};
#include <vector>
bool haspathsum(Node *node, int sum, std::vector<int> &root_to_leaf_values)
{
    root_to_leaf_values.emplace_back(node->data);
    if (!node->left && !node->right)
    {
        int s = 0;
        for (int val : root_to_leaf_values)
        {
            s += val;
        }
        if (s == sum)
        {
            return true;
        }
        return false;
    }

    if (node->left && haspathsum(node->left, sum, root_to_leaf_values))
    {
        return true;
    }

    root_to_leaf_values.pop_back();
    if (node->right)
    {
        return haspathsum(node->right, sum, root_to_leaf_values);
    }
    return false;
}

bool hasPathSum(Node *node, int sum)
{
    if (!node)
    {
        return false;
    }
    std::vector<int> root_to_leaf_values;
    return haspathsum(node, sum, root_to_leaf_values);
}