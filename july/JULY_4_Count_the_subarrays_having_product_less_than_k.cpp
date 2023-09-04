class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            long long product = 1;
            for (int j = i; j < n; j++)
            {
                product *= a[j];
                if (product < k)
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
        }
        return count;
    }
};