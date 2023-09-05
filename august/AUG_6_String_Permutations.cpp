class Solution
{
public:
    // Complete this function
    void permute(string str, int start, vector<string> &ans)
    {
        if (start == str.size() - 1)
        {
            ans.push_back(str);
            return;
        }
        for (int i = start; i < str.size(); i++)
        {
            swap(str[start], str[i]);
            permute(str, start + 1, ans);
        }
    }

    vector<string> permutation(string S)
    {
        // Your code here
        vector<string> ans;
        permute(S, 0, ans);
        // lexicographically increasing order
        sort(ans.begin(), ans.end());
        return ans;
    }
};