class Solution
{
    int arraySum, totalPaths = 0;
    vector<vector<int>> dp;
    int solve(int i, int target, int arr[], int N)
    {
        if (totalPaths == 2)
            return 0;

        if (i >= N)
        {
            if (target == 0)
            {
                totalPaths++;
                return 1;
            }
            return 0;
        }
        if (target < 0)
            return 0;
        if (dp[i][target] != -1)
            return dp[i][target];

        int path1 = solve(i + 1, target - arr[i], arr, N);
        int path2 = solve(i + 1, target, arr, N);
        return dp[i][target] = path1 + path2;
    }

public:
    int equalPartition(int N, int arr[])
    {
        arraySum = accumulate(arr, arr + N, 0);
        // not possible is arraySum is Odd
        if ((arraySum & 1) == 1)
            return 0;

        int i = 0, target = arraySum / 2;
        dp.resize(N + 1, vector<int>(target + 1, -1));
        int paths = solve(i, target, arr, N);
        // cout<<paths<<endl;
        return (paths >= 2);
    }
};