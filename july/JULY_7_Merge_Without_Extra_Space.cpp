class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int i, j, k;
        i = j = 0;
        k = n - 1;
        while (i <= k && j < m)
        {
            if (arr2[j] < arr1[i])
            {
                swap(arr2[j++], arr1[k--]);
            }
            // since arr[i] < arr[j]
            else
            {
                i++;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};