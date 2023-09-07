class Solution
{
    vector<int> arr;

public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node *root)
    {
        if (!root)
            return;
        arr.push_back(root->data);
        inorder(root->left);
        inorder(root->right);
    }
    Node *insert(Node *root, int data)
    {
        if (!root)
            return new Node(data);
        if (data < root->data)
            root->left = insert(root->left, data);
        if (data > root->data)
            root->right = insert(root->right, data);
        return root;
    }
    Node *binaryTreeToBST(Node *root)
    {
        // Your code goes here
        inorder(root);
        Node *newRoot = NULL;
        for (auto data : arr)
            newRoot = insert(newRoot, data);

        return newRoot;
    }
};