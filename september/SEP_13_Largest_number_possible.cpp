class Solution
{
public:
    string findLargest(int N, int S)
    {
        if (S == 0 && N != 1)
            return "-1";
        if ((9 * N) < S)
            return "-1";

        string str(N, '0');
        int i = 0;
        while (S)
        {
            if (S - 9 >= 0)
            {
                str[i++] = '9';
                S -= 9;
            }
            else
            {
                str[i++] = S + '0';
                S = 0;
            }
        }
        return str;
    }
};