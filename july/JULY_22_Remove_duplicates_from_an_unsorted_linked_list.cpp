/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
    Node *head;

    //  p t
    // 5 2 2 4 1 5
    //    .
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        // your code goes here
        this->head = head;
        Node *temp = head;
        unordered_map<int, int> map; //{data, frequency}
        Node *prev = NULL;
        while (temp != NULL)
        {
            int data = temp->data;
            map[data]++;

            if (map[data] > 1)
            {
                prev->next = prev->next->next;
                delete (temp);
                temp = prev;
            }
            prev = temp;
            temp = temp->next;
        }

        return this->head;
    }
};