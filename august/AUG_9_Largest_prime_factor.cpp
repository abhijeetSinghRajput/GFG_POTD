class Solution
{
public:
    long long int largestPrimeFactor(int N)
    {
        // code here
        long long i = 2, mx = INT_MIN;
        int squreRoot = sqrt(N);

        while (i <= sqrt(N))
        {
            if (N % i == 0)
            {
                N /= i;
                i = 2;
            }
            else
            {
                i++;
            }
            mx = max(mx, i);
        }
        if (N % i != 0)
        {
            mx = N;
        }
        return mx;
    }
};