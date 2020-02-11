struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }

} * head;

node *reverse(node *head)
{
    node *prev = nullptr;
    while (head)
    {
        node *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

struct node *reverse(struct node *head, int k)
{
    if (!head || !head->next || (k <= 0))
    {
        return head;
    }
    int count = 0;
    node temphead(0);
    node *temp_ptr = &temphead;
    while (head)
    {
        node splithead(0);
        node *split_ptr = &splithead;
        while (count < k && head)
        {
            split_ptr->next = head;
            head = head->next;
            split_ptr = split_ptr->next;
            ++count;
        }
        if (count < k || !head)
        {
            temp_ptr->next = reverse(splithead.next);
            return temphead.next;
        }
        count = 0;
        split_ptr->next = nullptr;
        temp_ptr->next = reverse(splithead.next);
        temp_ptr = splithead.next;
    }
    return temphead.next;
}