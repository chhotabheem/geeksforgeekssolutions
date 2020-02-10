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

void removeTheLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    bool loop_found = false;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            loop_found = true;
            break;
        }
    }
    if (!loop_found)
    {
        return;
    }
    int count = 0;
    while (fast->next != slow)
    {
        ++count;
        fast = fast->next;
    }
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    while (count--)
    {
        slow = slow->next;
    }

    slow->next = nullptr;
}