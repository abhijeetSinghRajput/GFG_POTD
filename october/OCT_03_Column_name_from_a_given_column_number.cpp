class Solution{
    public:
    string colName (long long int n)
    {
        string ans = "";
        while(n){
            int rem = (n - 1) % 26;
            ans.push_back(rem + 'A');
            n = (n - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};