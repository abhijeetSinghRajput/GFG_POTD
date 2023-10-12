/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

// ---------------- Brouth Forch Approach -----------------
//Time Complexity N²
//Auxillary Space N²

class Solution {
    void inorder(Node *root, vector<int> &vec){
        if(!root) return;
        
        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right, vec);
    }
    
    void solve(Node *root, vector<vector<int>> &vecs){
        if(!root) return;
        
        vector<int> vec;
        inorder(root, vec);
        
        if(vec.size() > 1)
        vecs.push_back(vec);
        
        solve(root->left, vecs);
        solve(root->right, vecs);
    }
public:
    int dupSub(Node *root) {
        vector<vector<int>> vecs;
        //at each node we traverse(inorder) whole sub tree N²
        solve(root, vecs);
        
        //N² to find dublicate vec
        for(int i = 0; i<vecs.size(); i++){
            for(int j = i+1; j< vecs.size(); j++){
                if(vecs[i] == vecs[j])
                return 1;
            }
        }
        
        return 0;
    }
};

// ---------------- Optimized Approach -----------------
//Time Complexity N
//Auxillary Space N

class Solution {
    
    unordered_map<string, int> map;
    
    string solve(Node *root){
        if(!root) return "";
        
        string left = solve(root->left);
        string right = solve(root->right);
        string ans = left + to_string(root->data) + right;
        
        if(root->left || root->right)
        map[ans]++;
        
        return ans;
    }
    
  public:
    int dupSub(Node *root) {
        solve(root);
        
        for(auto p : map){
            if(p.second > 1)
            return 1;
        }
        return 0;
    }
};