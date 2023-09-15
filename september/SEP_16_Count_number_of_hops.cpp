class Solution
{
    int mod = 1e9+7;
    vector<int> dp;
    long long solve(int n){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = ((solve(n-1) + solve(n-2))%mod + solve(n-3)) %mod;
    }
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        dp.resize(n+1, -1);
        return solve(n)%mod;
    }
};