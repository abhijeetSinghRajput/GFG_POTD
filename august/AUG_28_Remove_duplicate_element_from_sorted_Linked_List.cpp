

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    // your code goes here
    // 2 2 2 2
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == temp->data)
        {
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            delete (toDelete);
        }
        else
            temp = temp->next;
    }
    return head;
}