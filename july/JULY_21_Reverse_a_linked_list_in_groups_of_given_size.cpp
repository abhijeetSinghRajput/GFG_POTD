/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
public:
    struct node *reverse(struct node *head, int k)
    {
        // Complete this method
        if (head == NULL || k == 1)
            return head;
        struct node *prev, *curr, *next;
        curr = head;
        prev = next = NULL;

        int temp = k;
        while (temp-- && curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //    h          n
        //             p c
        // N<-1<-2<-2<-4 5->6->7->8->N;
        head->next = reverse(curr, k);
        return prev;
    }
};