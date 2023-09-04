/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution{
      public:
    //   int depth = 0;
      int max(int x,int y){
      return (x>y)?x:y;
     }
    /*You are required to complete this method*/
    int maxDepth(Node *root) {
        // Your code here
        if(root == NULL){
            return 0;
        }
        int leftDepth = 1, rightDepth = 1;
        leftDepth += maxDepth(root->left);
        rightDepth += maxDepth(root->right);
        return max(leftDepth,rightDepth);
    }
};