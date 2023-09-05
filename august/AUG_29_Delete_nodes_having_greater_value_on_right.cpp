/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    void reverse(Node *&head)
    {
        Node *prev = NULL, *curr = head;
        while (curr)
        {
            Node *nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        head = prev;
    }
    void deleteNode(Node *prev, Node *toDelete)
    {
        prev->next = toDelete->next;
        delete (toDelete);
    }

public:
    Node *compute(Node *head)
    {
        // your code goes here

        reverse(head);
        // c
        // 3->2->6->5->11->10->15->12
        Node *curr = head;
        while (curr)
        {
            if (curr->next && curr->next->data < curr->data)
            {
                deleteNode(curr, curr->next);
            }
            else
                curr = curr->next;
        }
        reverse(head);
        return head;
    }
};