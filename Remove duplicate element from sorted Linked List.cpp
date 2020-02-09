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

Node *removeDuplicates(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *res_ptr = head;
    Node *curr = head->next;
    while (curr)
    {
        if (curr->data == res_ptr->data)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else
        {
            res_ptr->next = curr;
            res_ptr = res_ptr->next;
            curr = curr->next;
        }
    }

    res_ptr->next = nullptr;
    return head;
}