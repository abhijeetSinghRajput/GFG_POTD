// User function Template for C++

class Solution
{
    stack<int> aux;
    void copyInAux(stack<int> &St)
    {
        if (St.empty())
            return;
        int top = St.top();
        St.pop();
        copyInAux(St);
        aux.push(top);
    }

public:
    void Reverse(stack<int> &St)
    {
        copyInAux(St);
        while (!aux.empty())
        {
            St.push(aux.top());
            aux.pop();
        }
    }
};