class Solution
{
    int n, mod = 1e9 + 7;
    vector<vector<int>> dp;
    int solve(int i, int target, int arr[])
    {
        // Base cases
        if (i >= n)
        {
            if (target == 0)
                return 1;
            return 0;
        }
        // target became -ve
        if (target < 0)
            return 0;

        if (dp[i][target] != -1)
            return dp[i][target];

        int include = solve(i + 1, target - arr[i], arr) % mod;
        int exclude = solve(i + 1, target, arr) % mod;

        return dp[i][target] = (include + exclude) % mod;
    }

public:
    int perfectSum(int arr[], int n, int sum)
    {
        this->n = n;
        dp.resize(n + 1, vector<int>(sum + 1, -1));
        return solve(0, sum, arr);
    }
};