class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        //code here
        if(n == 1) return {1};
        if(n == 2) return {1, 1};
        
        vector<long long> dp(n);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp;
    }
};