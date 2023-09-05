// User function template for C++

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        // your code here
        if (k > s.size())
            return -1;

        unordered_map<char, int> map;
        int maxLength = -1, l = 0;

        for (int r = 0; r < s.size(); r++)
        {
            map[s[r]]++;

            while (map.size() > k)
            {
                map[s[l]]--;
                if (map[s[l]] == 0)
                    map.erase(s[l]);
                l++;
            }
            if (map.size() == k)
                maxLength = max(maxLength, (r + 1) - l);
        }

        return maxLength;
    }
};