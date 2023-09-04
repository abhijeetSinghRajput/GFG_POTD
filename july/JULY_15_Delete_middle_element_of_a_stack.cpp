// User function template for C++

class Solution
{
public:
    // Function to delete middle element of a stack.

    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        // code here..
        // if it's a middle element
        if (sizeOfStack <= 1)
        {
            s.pop();
            return;
        }
        int poped = s.top();
        s.pop();
        sizeOfStack -= 2;
        deleteMid(s, sizeOfStack);
        s.push(poped);
    }
};