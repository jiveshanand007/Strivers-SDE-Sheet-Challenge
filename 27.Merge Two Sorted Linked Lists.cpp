#include <bits/stdc++.h>

Node<int> *sortTwoLists(Node<int> *list1, Node<int> *list2)
{
    Node<int> *temp;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }
    if (list1->data < list2->data)
    {
        temp = list1;
        temp->next = sortTwoLists(list1->next, list2);
    }
    else
    {
        temp = list2;
        temp->next = sortTwoLists(list1, list2->next);
    }
    return temp;
}
