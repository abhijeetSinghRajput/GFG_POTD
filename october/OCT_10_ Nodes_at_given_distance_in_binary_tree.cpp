class Solution
{
private:
    int T, K, foundAt = -1;
    void collect(Node *root, int d, vector<int> &ans)
    {
        if(!root) return;
        // if(d <= 0) return;

        if(d == 0){
            ans.push_back(root->data);
            return;
        }

        collect(root->left, d-1, ans);
        collect(root->right, d-1, ans);
    }
    bool find(Node *root, vector<int> &ans, int level)
    {
        if (!root)
            return false;

        if (root->data == T)
        {
            foundAt = level;
            collect(root, K, ans);
            return true;
        }

        if (find(root->left, ans, level+1))
        {
            int d = foundAt - level;
            if(d == K) ans.push_back(root->data);
            collect(root->right,K - d - 1, ans);//-1 for right
            return true;
        }

        if (find(root->right, ans, level+1))
        {
            int d = foundAt - level;
            if(d == K) ans.push_back(root->data);
            collect(root->left,K - d - 1, ans);//-1 for ->left
            return true;
        }
        return false;
    }

public:
    vector<int> KDistanceNodes(Node *root, int target, int k)
    {
        vector<int> ans;
        this->T = target;
        this->K = k;
        
        find(root, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};