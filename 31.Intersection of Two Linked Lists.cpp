Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *tail = firstHead;
    while (tail->next)
        tail = tail->next;
    tail->next = firstHead;
    Node *slow = secondHead, *fast = secondHead;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = secondHead;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            tail->next = NULL;
            return slow;
        }
    }
    tail->next = NULL;
    return NULL;
}