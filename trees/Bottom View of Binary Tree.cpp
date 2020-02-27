struct Node
{
    int data;
    Node *left, *right;

    Node(int key)
    {
        data = key;
        left = right = nullptr;
    }
};

#include <map>
#include <tuple>
#include <iostream>
void bottom_view(Node *root, int height, int width, std::map<int, std::pair<int, int>> &width_height_map)
{
    if (!root)
    {
        return;
    }

    auto iter = width_height_map.find(width);
    if (iter == width_height_map.end())
    {
        std::pair<int, int> ht_val_pair(height, root->data);
        width_height_map[width] = ht_val_pair;
    }
    else
    {
        if (iter->second.first <= height)
        {
            iter->second.first = height;
            iter->second.second = root->data;
        }
    }
    bottom_view(root->left, height + 1, width - 1, width_height_map);
    bottom_view(root->right, height + 1, width + 1, width_height_map);
}
void bottomView(Node *root)
{
    std::map<int, std::pair<int, int>> width_height_map;
    bottom_view(root, 0, 0, width_height_map);
    for (auto &kv : width_height_map)
    {
        std::cout << kv.second.second << " ";
    }
}