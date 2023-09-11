class Solution
{
public:
    int isPerfectNumber(long long N)
    {
        // code here
        long long sum = 0;
        for (int i = 1; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                sum += i;
                if (i * i != N)
                {
                    sum += N / i;
                }
            }
        }
        return sum / 2 == N;
    }
};