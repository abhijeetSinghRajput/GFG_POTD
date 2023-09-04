class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        int count = 0;
        while (N)
        {
            if (N % 2 == 1)
            {
                count++;
            }
            N /= 2;
        }
        return count;
    }
};