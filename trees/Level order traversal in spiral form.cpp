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
#include <stack>
#include <iostream>

void printSpiral(Node *root)
{
    if (!root)
    {
        return;
    }
    std::queue<Node *> que;
    que.push(root);
    auto level = 0;
    while (!que.empty())
    {
        ++level;
        auto n = que.size();
        std::stack<Node *> stk;
        while (n--)
        {
            auto node = que.front();
            que.pop();
            std::cout << node->data << " ";
            if (level % 2 == 0)
            {
                if (node->left)
                {
                    stk.push(node->left);
                }
                if (node->right)
                {
                    stk.push(node->right);
                }
            }
            else
            {
                if (node->right)
                {
                    stk.push(node->right);
                }
                if (node->left)
                {
                    stk.push(node->left);
                }
            }
        }
        while (!stk.empty())
        {
            que.push(stk.top());
            stk.pop();
        }
    }
}