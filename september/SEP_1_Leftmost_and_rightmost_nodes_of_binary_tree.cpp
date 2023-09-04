/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{

// Your code goes here
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int size = q.size();
       bool leftmost = true;
       Node *curr;
       for(int i = 0; i < size; i++){
           curr = q.front();
           q.pop();
           if(leftmost){
               leftmost = false;
               cout<<curr->data<<" ";
           }
           
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
       }
       if(size > 1)
           cout<<curr->data<<" ";
   }
}