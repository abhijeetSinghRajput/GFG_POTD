class Solution
{

    long long mod = 1000000007;

    long long fastPow(long long base, long long exp)
    {
        if (exp == 0)
            return 1;

        if (exp % 2 == 0)
        {
            long long p = fastPow(base, exp / 2) % mod;
            return (p * p) % mod;
        }

        return ((base % mod) * fastPow(base, exp - 1) % mod) % mod;
    }

    long long reverse(long long n)
    {
        long long rev = 0;
        while (n)
        {
            rev += (n % 10);
            rev *= 10;
            n /= 10;
        }
        return rev / 10;
    }

public:
    // You need to complete this fucntion

    long long power(int N, int R)
    {
        // Your code here
        //  (N to R)mod(109 + 7).
        long long rev = reverse(N);
        // cout<<N<<" "<<rev<<endl;
        return fastPow(N, rev);
    }
    //
};