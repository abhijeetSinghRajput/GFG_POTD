class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        unsigned int mask = n & (n-1);
        return log2(mask ^ n) + 1;
    }
};