struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *reverse(Node *node)
{
    Node *prev = nullptr;
    while (node)
    {
        Node *temp = node->next;
        node->next = prev;
        prev = node;
        node = temp;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if (!head || !head->next)
    {
        return true;
    }
    Node *fast = head;
    Node *slow = head;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *secheadptr = reverse(slow->next);
    Node *sec = secheadptr;
    while (sec)
    {
        if (sec->data != head->data)
        {
            slow->next = reverse(secheadptr);
            return false;
        }
        sec = sec->next;
        head = head->next;
    }
    slow->next = reverse(secheadptr);
    return true;
}
#include <stack>

bool isPalindrome_using_stack(Node *head)
{
    if (!head)
    {
        return false;
    }
    if (!head->next)
    {
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    std::stack<int> stk;
    int count = 0;
    while (fast)
    {
        ++count;
        fast = fast->next;
        if (!fast)
        {
            break;
        }
        stk.push(slow->data);
        slow = slow->next;
        ++count;
        fast = fast->next;
    }
    if (count % 2 != 0)
    {
        slow = slow->next;
    }

    while (!stk.empty() || slow)
    {
        int val = stk.top();
        stk.pop();
        if (val != slow->data)
        {
            return false;
        }
        slow = slow->next;
    }
    if (!stk.empty() || slow)
    {
        return false;
    }
    return true;
}
