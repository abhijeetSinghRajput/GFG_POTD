class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        map<int, int> map;
        for (int i : nums)
        {
            map[i]++;
        }
        vector<int> ans;
        for (auto i : map)
        {
            if (i.second == 1)
                ans.push_back(i.first);
        }
        return ans;
    }
};