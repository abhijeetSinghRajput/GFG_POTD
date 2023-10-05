class Solution
{
    struct Node *tail = NULL;
    void push_back(struct Node *newNode){
        if(!tail->next){
            tail->next = newNode;
        }
        else{
            struct Node *nextNode = tail->next;
            tail->next = newNode;
            newNode->next = nextNode;
        }
    }
    public:
    void rearrange(struct Node *odd)
    {
        
        //10->4->9->1->3->5->9->4 ->4
        //    4     1     5    4   alt nodes
        
        //10->9->3->9
        
        //reverse alt and append to the back
        //10->9->3->9->4->5->1->4
        
        if(!odd || !odd->next) return;
        
        tail = odd;
        while(tail->next != NULL){
            tail = tail->next;
        }
        
        struct Node *curr = odd->next, *prev = odd;
        int i = 2;
        
        while(curr != tail){
            if(i % 2 == 0){
                prev->next = curr->next;
                curr->next = NULL;
                
                push_back(curr);
                curr = prev;
            }
            
            prev = curr;
            curr = curr->next;
            i++;
        }
    }
};