class Solution{
    
    pair<char, int> solve(Node *root){
        if(!root) return {true, 0};
        
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        
        pair<bool, int> p;
        
        p.second = 1 + max(left.second, right.second);//calculating height
        p.first = left.first && right.first && abs(left.second - right.second) <= 1;
        return p;
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        return solve(root).first;
    }
};