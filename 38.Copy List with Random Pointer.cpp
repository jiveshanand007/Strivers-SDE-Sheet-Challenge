
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        Node *ptr = head;
        while (ptr)
        {
            if (ptr->random)
            {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        Node *dummy = new Node(0);
        ptr = head;
        temp = dummy;
        Node *fast;
        while (ptr)
        {
            fast = ptr->next->next;
            temp->next = ptr->next;
            ptr->next = fast;
            temp = temp->next;
            ptr = fast;
        }
        return dummy->next;
    }
};