class Solution
{
    // map<pair<int, int> , int> dp;
    long long int solve(int need, int coins[], int i, auto &dp)
    {
        // BASE CASES
        if (i < 0 || need < 0)
            return 0;
        // need pura hua
        if (need == 0)
            return 1;

        // pair<int, int> p = {need, i};
        // if(dp.find(p) != dp.end()) return dp[p];

        if (dp[need][i] != -1)
            return dp[need][i];
        // coin taken
        long long int taken = solve(need - coins[i], coins, i, dp);
        // coin not taken
        long long int notTaken = solve(need, coins, i - 1, dp);

        return dp[need][i] = taken + notTaken;
    }

public:
    long long int count(int coins[], int N, int sum)
    {

        // code here.
        // vector<vector<long long int>> dp(sum + 1, vector<long long int>(N+1, -1));
        // return solve(sum, coins, N-1, dp);

        vector<long long int> dp(sum + 1, 0);
        dp[0] = 1;
        // PERMUTATION EXIST LIKE:- FOR 3 {1 : 2}, {2 : 1}

        // for(int i = 1; i< sum + 1; i++){
        //     for(int j = 0; j<N; j++){
        //         //how many way to pay i
        //         if(coins[j] <= i)
        //             dp[i] += dp[i - coins[j]];
        //             //i ko j coin se pay kiya
        //     }
        // }

        for (int i = 0; i < N; i++)
        { // for each coins
            for (int j = 1; j < sum + 1; j++)
            { // possible ways to get j
                int coin = coins[i];
                if (coin <= j)
                    dp[j] += dp[j - coin];
            }
        }
        return dp[sum];
    }
};