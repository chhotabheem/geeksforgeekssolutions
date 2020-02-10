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

int detectloop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}