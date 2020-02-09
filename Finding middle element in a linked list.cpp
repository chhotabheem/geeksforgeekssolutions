struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

int getMiddle(Node *head)
{
    if (!head)
    {
        return -1;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (!fast->next)
    {
        return slow->data;
    }
    return slow->next->data;
}