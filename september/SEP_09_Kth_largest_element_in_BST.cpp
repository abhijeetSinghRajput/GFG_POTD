/*The Node structure is defined as
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

// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
    vector<int> arr;
    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->right);
        arr.push_back(root->data);
        inorder(root->left);
    }

public:
    int kthLargest(Node *root, int K)
    {
        // Your code here
        inorder(root);
        return arr[K - 1];
    }
};