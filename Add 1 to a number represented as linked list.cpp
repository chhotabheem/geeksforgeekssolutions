struct Node
{
    int data;
    Node *next;
};

#include <iostream>

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    while (head)
    {
        Node *temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}
Node *addOne(Node *head)
{
    if (!head)
    {
        Node *newhead = new Node;
        newhead->next = nullptr;
        newhead->data = 1;
        return newhead;
    }
    Node *rhead = reverse(head);
    Node *curr = rhead;
    int carry = 1;

    while (curr)
    {
        int sum = curr->data + carry;
        curr->data = sum % 10;
        carry = sum / 10;
        curr = curr->next;
    }
    head = reverse(rhead);
    if (carry)
    {
        Node *newhead = new Node;
        newhead->data = carry;
        newhead->next = head;
        return newhead;
    }
    return head;
}