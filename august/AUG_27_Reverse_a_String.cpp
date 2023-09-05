// User function Template for C++
class Solution
{
public:
    string reverseWord(string str)
    {
        // Your code goes here
        for (int i = 0; i < str.size() / 2; i++)
        {
            swap(str[i], str[str.size() - 1 - i]);
        }
        return str;
    }
};