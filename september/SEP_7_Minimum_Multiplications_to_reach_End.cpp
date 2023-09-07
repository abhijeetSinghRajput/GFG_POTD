class Solution
{
    int mod = 1e5;

public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        // code here
        if (start == end)
            return 0;
        queue<int> q;
        q.push(start);
        int level = 0;
        vector<bool> dp(mod, false);
        dp[start] = true;

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int x = q.front();
                q.pop();
                if (x == end)
                    return level;

                for (auto i : arr)
                {
                    int product = ((x % mod) * (i % mod)) % mod;
                    if (!dp[product])
                    {
                        q.push(product);
                        dp[product] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};