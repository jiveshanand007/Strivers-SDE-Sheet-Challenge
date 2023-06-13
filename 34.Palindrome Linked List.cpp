#include <bits/stdc++.h>
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    while (curr)
    {
        LinkedListNode<int> *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
LinkedListNode<int> *findMiddle(LinkedListNode<int> *head)
{
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool isPalindrome(LinkedListNode<int> *head)
{
    if (!head || !head->next)
        return true;
    LinkedListNode<int> *first = head;
    LinkedListNode<int> *mid = findMiddle(head);
    LinkedListNode<int> *last = reverse(mid->next);
    while (last != NULL)
    {
        if (first->data != last->data)
            return false;
        first = first->next;
        last = last->next;
    }
    return true;
}