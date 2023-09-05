// function to find longest common subsequence

class Solution
{

public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        //  E C B D E B D
        // B 0 0 0 0 0 0 0 0
        // C 0
        // A 0
        // C 0
        // C 0
        // B 0
        // D 0
        // A 0

        int dp[n + 1][m + 1];
        for (int i = 0; i < (n + 1); i++)
        {
            for (int j = 0; j < (m + 1); j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (s1[i - 1] != s2[j - 1])
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                else
                    dp[i][j] = 1 + dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};