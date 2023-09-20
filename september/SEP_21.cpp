class Solution
{
    vector<int> dp;
    int solve(int i, int arr[], int n){
        if(i >= n) return 0;
        
        //aplying dp
        if(dp[i] != -1) return dp[i];
        
        int looted = arr[i] + solve(i+2, arr, n);//looted
        int skiped = solve(i+1, arr, n);//skiped
        
        return dp[i] = max(looted, skiped);
    }
    
public:

    int FindMaxSum(int arr[], int n)
    {
        dp.resize(n+1, -1);
        return max(solve(0, arr, n), solve(1, arr, n));
    }
};