class Solution
{
public:
    void print(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int maxIndexDiff(int arr[], int n)
    {
        // code here
        int preMin[n], postMax[n];
        preMin[0] = arr[0];
        postMax[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < preMin[i - 1])
            {
                preMin[i] = arr[i];
            }
            else
            {
                preMin[i] = preMin[i - 1];
            }
            if (arr[n - 1 - i] > postMax[n - i])
            {
                postMax[n - 1 - i] = arr[n - 1 - i];
            }
            else
            {
                postMax[n - 1 - i] = postMax[n - i];
            }
        }
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n)
        {
            if (postMax[j] >= preMin[i])
            {
                ans = max(ans, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};