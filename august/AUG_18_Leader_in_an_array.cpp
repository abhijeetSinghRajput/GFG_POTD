

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> ans;
        stack<int> stack;
        for (int i = n - 1; i >= 0; i--)
        {
            if (stack.empty() || stack.top() <= a[i])
                stack.push(a[i]);
        }
        while (!stack.empty())
        {
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
};