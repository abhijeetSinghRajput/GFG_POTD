class Solution
{
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        // Your code here
        unordered_map<char, int> map;
        for (char ch : S)
        {
            map[ch]++;
        }
        for (char ch : S)
        {
            if (map[ch] == 1)
                return ch;
        }
        return '$';
    }
};