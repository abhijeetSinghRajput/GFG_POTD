class Solution{
    vector<int> list;
    Node *head = NULL;
    
    void inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        list.push_back(root->data);
        inorder(root->right);
    }
    
    Node *insert(Node *root, int data){
        if(!root) return new Node(data);
        
        if(data < root->data){
            root->left = insert(root->left, data);
        }
        else if(data > root->data){
            root->right = insert(root->right, data);
        }
        return root;
    }
    
    void builtTree(int left, int right){
        if(left > right) return;
        
        int mid = left + (right - left)/2;
        head = insert(head, list[mid]);
        
        builtTree(left, mid-1);
        builtTree(mid+1, right);
    }
public:
    Node* buildBalancedTree(Node* root)
    {
        inorder(root);
        builtTree(0, list.size()-1);
        return head;
    }
};