// User function Template for C++
class Solution
{
public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
        {
            map[arr[i]]++;
        }
        unordered_set<int> set;
        for (auto value : map)
        {
            // checking if same frequency is already present or not before inserting
            if (set.find(value.second) != set.end() && *set.find(value.second) == value.second)
                return false;

            set.insert(value.second); // inserting frequency
            // cout<<value.first<<" "<<value.second<<endl;
        }
        return true;
    }
};