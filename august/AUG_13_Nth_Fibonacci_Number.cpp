// User function Template for C++
class Solution
{
public:
    int nthFibonacci(int n)
    {
        // code here
        if (n <= 1)
            return n;
        int a = 0, b = 1, fib;
        int mod = 1e9 + 7;

        for (int i = 2; i <= n; i++)
        {
            fib = (a + b) % mod;
            a = b;
            b = fib;
        }
        return fib;
    }
};