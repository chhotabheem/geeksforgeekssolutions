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

int getNthFromLast(Node *head, int n)
{
    if (!head || n <= 0)
    {
        return -1;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && n--)
    {
        fast = fast->next;
    }
    if (n > 0)
    {
        return -1;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}