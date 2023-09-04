/* You are required to complete the function below
 *  arr[]: input array
 *  n: size of array
 */
class Solution
{
public:
    // Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                // printf("(%d)+(%d)+(%d) = %d\n",arr[i],arr[j],arr[k],sum);
                if (sum > 0)
                {
                    --k;
                }
                else if (sum < 0)
                {
                    ++j;
                }
                else if (sum == 0)
                {
                    return true;
                }
            }
        }
        // cout<<endl;
        return false;
    }
};