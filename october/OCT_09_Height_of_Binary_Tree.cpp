class Solution{
    public:
    int height(struct Node* node){
        return (!node)? 0 : 1 + max(height(node->left), height(node->right));
    }
};