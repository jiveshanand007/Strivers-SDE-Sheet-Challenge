
Node *removeKthNode(Node *head, int K)
{
    Node *dummy = new Node();
    dummy->next = head;
    Node *slow = dummy;
    Node *fast = dummy;
    while (fast->next != NULL)
    {
        if (K <= 0)
        {
            slow = slow->next;
        }
        fast = fast->next;
        K--;
    }
    Node *del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return dummy->next;
}
