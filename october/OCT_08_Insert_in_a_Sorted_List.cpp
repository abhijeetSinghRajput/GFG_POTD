class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node *newnode = new Node(data);
        if(data < head->data){
            newnode->next = head;
            head = newnode;
            return head;
        }
        
        Node *prev = head, *curr = head->next;
        while(curr && data > curr->data){
            prev = curr;
            curr = curr->next;
        }
        
        prev->next = newnode;
        newnode->next = curr;
        
        return head;
    }
};