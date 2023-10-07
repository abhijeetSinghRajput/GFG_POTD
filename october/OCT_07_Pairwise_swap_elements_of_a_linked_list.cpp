class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        if(!head || !head->next) return head;

        Node *prev = head, *curr = head->next;
        head = curr;
        while(curr){
            Node *nextNode = curr->next;
            curr->next = prev;
        
            if(!nextNode){
                prev->next = NULL;
                break;
            }
            
            //odd
            if(!nextNode->next){
                prev->next = nextNode;
                break;
            }
            
            prev->next = nextNode->next;
            prev = nextNode;
            curr = prev->next;
        }
        
        return head;
    }
};