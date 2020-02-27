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
void leftView(Node *root)
{
    if (!root)
    {
        return;
    }
    std::queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int n = que.size();
        std::cout << que.front()->data << " ";
        while (n--)
        {
            Node *node = que.front();
            que.pop();
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
    }
}
