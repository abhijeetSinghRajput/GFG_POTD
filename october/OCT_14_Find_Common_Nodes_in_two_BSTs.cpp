
class Solution
{
    unordered_set<int> set;
    vector<int> ans;
    void inorder1(Node *root){
        if(!root) return;
        
        inorder1(root->left);
        set.insert(root->data);
        inorder1(root->right);
    }
    
    void inorder2(Node *root){

        if(!root) return;

        
        inorder2(root->left);
        if(set.find(root->data) != set.end())
        ans.push_back(root->data);
        inorder2(root->right);
    }
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     inorder1(root1);
     inorder2(root2);
     return ans;
    }
};






