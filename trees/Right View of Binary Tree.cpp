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

#include <queue>
#include <iostream>
void rightView(Node *root)
{
    if (!root)
    {
        return;
    }
    std::queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        std::cout << que.front()->data << " ";
        int n = que.size();
        while (n--)
        {
            Node *node = que.front();
            que.pop();
            if (node->right)
            {
                que.push(node->right);
            }
            if (node->left)
            {
                que.push(node->left);
            }
        }
    }
}
