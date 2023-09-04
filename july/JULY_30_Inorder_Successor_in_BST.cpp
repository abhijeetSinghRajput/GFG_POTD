/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    Node *ans = NULL;
    bool inRight = false, ancestor = false;

    void traverse(Node *root, Node *x)
    {
        if (root == NULL)
        {
            return;
        }

        if (root == x)
        {
            // ai. in case right NULL ho tab inorder direct apne ancestor ke pas jata hai
            if (root->right == NULL)
            {
                ancestor = true;
                return;
            }
            // bi. iska mtlb successor right sub tree me present hai
            else if (root->right != NULL)
            {
                inRight = true;
                traverse(root->right, x);
            }
        }

        traverse(root->left, x);

        if (inRight && ans == NULL)
        {
            ans = root;
            inRight = false;
        }
        if (ancestor && ans == NULL)
        {
            ans = root;
            ancestor = false;
        }

        traverse(root->right, x);
    }

public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        traverse(root, x);
        return ans;
    }
};