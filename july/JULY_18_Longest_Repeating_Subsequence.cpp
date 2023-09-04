class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        int n = str.size();
        int dp[n + 1][n + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (str[i - 1] == str[j - 1] && j != i)
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][n];
    }
};