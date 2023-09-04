/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution
{
    unordered_map<int, int> map;
    int level = 1;
    void helper(Node *root)
    {
        if (root == NULL)
        {
            level--;
            return;
        }
        // if no element is present at such level
        if (map.find(level) == map.end())
        {
            map[level] = root->data;
        }
        // printf("%d %d\n",level,root->data);
        level++;
        helper(root->right);
        level++;
        helper(root->left);
        level--;
    }

public:
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        // Your Code here
        helper(root);
        vector<int> ans;
        for (int i = 1; i <= map.size(); i++)
        {
            ans.push_back(map[i]);
        }
        return ans;
    }
};
