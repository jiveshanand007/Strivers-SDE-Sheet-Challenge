/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    if (l1 == NULL && l2 == NULL)
        return NULL;
    if (l1 == NULL || l2 == NULL)
        return l1 ? l1 : l2;

    int carry = (l1->data + l2->data) / 10;
    Node *root = new Node((l1->data + l2->data) % 10);
    Node *carryNode = new Node(carry);
    if (carry)
        root->next = addTwoNumbers(addTwoNumbers(l1->next, carryNode), l2->next);
    else
        root->next = addTwoNumbers(l1->next, l2->next);

    return root;
}
