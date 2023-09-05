class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        // code
        sort(a.begin(), a.end());
        // 1 3 4 7 9 9 12 56
        // 0 1 2 3 4 5 6  7 8
        long long ans = INT_MAX;
        for (int i = 0; i < n - (m - 1); i++)
        {
            long long diff = a[i + m - 1] - a[i];
            ans = min(ans, diff);
        }
        return ans;
    }
};