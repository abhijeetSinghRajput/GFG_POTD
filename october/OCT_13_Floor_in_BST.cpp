class Solution{
    void find(Node *root, int x,int &ans){
        if(!root) return;
        
        if(root->data > x){
            //then look for another subTree
            find(root->left, x, ans);
        }
        else if(root->data < x){
            //it may be an ans
            ans = root->data;
            find(root->right, x, ans);
        }
        else{
            ans = root->data;
            return;
        }
    }
public:
    int floor(Node* root, int x) {
        // Code here
        int ans = -1;
        find(root, x, ans);
        return ans;
    }
};