class Solution
{
    int mod = 1e9 + 7;

public:
    int findCatalan(int n)
    {
        // code here
        long long dp[n + 1];
        dp[0] = dp[1] = 1;

        for (int i = 2; i < n + 1; i++)
        {
            dp[i] = 0;
            for (int j = 0; j < i; j++)
            {
                dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j]) % mod) % mod;
            }
        }
        return (int)dp[n];
    }
};