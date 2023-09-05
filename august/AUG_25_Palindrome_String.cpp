

// User function template for C++
class Solution
{
public:
    int isPalindrome(string S)
    {
        // Your code goes here
        for (int i = 0; i < S.size() / 2; i++)
        {
            if (S[i] != S[S.size() - 1 - i])
                return 0;
        }
        return 1;
    }
};