// User function template for C++
class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here
        int freq = n;
        int i = 0, j = n - 1;
        // 1 1 2 2 2 2 3
        //     i     i
        while (i <= j)
        {
            if (arr[i] < x)
            {
                i++;
                freq--;
            }
            if (arr[j] > x)
            {
                j--;
                freq--;
            }
            if (arr[i] == x && arr[j] == x)
                break;
        }
        return freq;
    }
};