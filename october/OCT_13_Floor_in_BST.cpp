// ------------------ Brute Force Approach ------------------------

// Function to search a node in BST.
// class Solution{
//     vector<int> arr;
//     void inorder(Node *root){
//         if(!root)return;
        
//         inorder(root->left);
//         arr.push_back(root->data);
//         inorder(root->right);
//     }
// public:
//     int floor(Node* root, int x) {
//         // Code here
//         inorder(root);
//         int ans = -1;
//         for(auto i : arr){
//             if(i > x){
//                 return ans;
//             }
//             ans = i;
//         }
//         return ans;
//     }
// };


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