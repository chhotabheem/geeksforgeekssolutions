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

Node *deleteMid(Node *head)
{
    if (!head)
    {
        return nullptr;
    }
    if (!head->next)
    {
        delete head;
        return nullptr;
    }
    Node *slow = head;
    Node *prev = nullptr;
    Node *fast = head;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    if (!fast->next)
    {
        prev->next = slow->next;
        delete slow;
        return head;
    }
    Node *temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return head;
}