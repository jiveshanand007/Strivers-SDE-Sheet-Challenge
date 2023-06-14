/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    if (!head || !head->next)
        return head;
    Node *temp = head;
    int cnt = 1;
    while (temp->next)
    {
        temp = temp->next;
        cnt++;
    }
    temp->next = head;
    k %= cnt;
    k = cnt - k;
    temp = head;
    while (k > 1)
    {
        temp = temp->next;
        k--;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}