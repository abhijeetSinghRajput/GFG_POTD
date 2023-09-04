// User function Template for C++
class Solution
{
public:
    int setSetBit(int x, int y, int l, int r)
    {
        // code here
        --l;
        --r;
        for (int i = l; i <= r; i++)
        {
            x |= ((y >> i) & 1) << i;
        }
        return x;
    }
};