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

bool areIdentical(struct Node *head1, struct Node *head2)
{
    while (head1 && head2)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (!head1 && !head2)
    {
        return true;
    }
    return false;
}