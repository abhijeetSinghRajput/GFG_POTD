// function Template for C++

// Function to reverse the queue.
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        stack<int> stack;
        while (!q.empty())
        {
            stack.push(q.front());
            q.pop();
        }
        while (!stack.empty())
        {
            q.push(stack.top());
            stack.pop();
        }
        return q;
    }
};