#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/
Node *reverse(Node *first, Node *last)
{
    Node *prev = last;
    while (first != last)
    {
        Node *next = first->next;
        first->next = prev;
        prev = first;
        first = next;
    }
    return prev;
}
Node *reverseKGroup(Node *head, int k, int b[], int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    while (b[k] == 0 && k < n)
        k++;
    if (k < n)
    {

        Node *temp = head;
        for (int i = 0; i < b[k]; i++)
        {
            if (temp == NULL)
            {
                break;
            }
            temp = temp->next;
        }

        auto new_head = reverse(head, temp);

        head->next = reverseKGroup(temp, k + 1, b, n);
        return new_head;
    }
    return head;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    return reverseKGroup(head, 0, b, n);
}