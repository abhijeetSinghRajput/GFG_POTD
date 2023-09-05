class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        // Your code here
        int sum = 0;
        vector<int> ans;
        for (int i = 0, j = 0; j < n; j++)
        {
            sum += arr[j];
            while (sum > s)
            {
                sum -= arr[i++];
            }
            if (sum == s && i <= j)
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                return ans;
            }
        }
        ans.push_back(-1);
        return ans;
    }
};