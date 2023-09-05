

class Solution
{
public:
    int maxOnes(int a[], int n)
    {
        // kadan's algo
        // make 0 ->  1
        //      1 -> -1
        //  1 0 0  1 0 0  1
        //-1 1 1 -1 1 1 -1

        // 1
        int maxSub = INT_MIN;
        int sum = 0, ones = 0;
        for (int i = 0; i < n; i++)
        {
            int bit;
            if (a[i] == 0)
                bit = 1;
            else
            {
                bit = -1;
                ones++;
            }
            if (sum + bit >= bit)
                sum += bit;
            else
                sum = bit;
            maxSub = max(maxSub, sum);
        }
        // edge case  1  1  1  1  1
        //           -1 -1 -1 -1 -1

        if (maxSub < 0)
            return ones;
        return ones + maxSub;
    }
};