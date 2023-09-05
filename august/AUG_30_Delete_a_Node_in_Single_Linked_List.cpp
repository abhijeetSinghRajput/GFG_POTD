

/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

/*You are required to complete below method*/
Node *deleteNode(Node *head, int x)
{
    // Your code here
    if (!head)
        return NULL;

    Node *toDelete = NULL;
    if (x == 1)
    {
        toDelete = head;
        head = head->next;
        delete (toDelete);
        return head;
    }
    Node *temp = head;

    for (int i = 1; i < x - 1; i++, temp = temp->next)
        ;

    toDelete = temp->next;
    temp->next = toDelete->next;
    delete (toDelete);
    return head;
}