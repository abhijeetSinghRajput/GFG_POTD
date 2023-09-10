class Solution
{
public:
    bool isLucky(int n)
    {
        // code here
        // 1 3 5
        // 3
        for (int i = 2; n >= i; i++)
        {
            if (n % i == 0)
                return false;
            // how many will remove
            int removed = n / i;
            // rest
            n -= removed;
        }
        return true;
    }
};