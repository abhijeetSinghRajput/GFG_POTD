class Solution
{
    // get first single frequency
    char getfsf(string str, int size)
    {
        unordered_map<char, int> map;
        for (int i = 0; i <= size; i++)
        {
            // searching single frequncy char by char
            if (map[str[i]] == 1)
            {
                return str[i];
            }
        }
        return '#';
    }

public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string result;
        // APPROCH 1
        //   for(int i = 0; i<A.size(); i++){
        //       result += getfsf(A,i);
        //   }

        // APPROCH 2
        vector<int> freqCounter(26, 0);
        queue<char> q;
        for (auto i : A)
        {
            // mentain freq
            //  'a' - 'a' = 0;
            //  'b' - 'a' = 1;
            //  'c' - 'a' = 3;
            //  and so on.....
            freqCounter[i - 'a']++;

            // containing only valid char
            if (freqCounter[i - 'a'] == 1)
                q.push(i);

            // jabtak queue ke front ke element ka freq > 1 then nikal do
            while (!q.empty() && freqCounter[q.front() - 'a'] > 1)
            {
                q.pop();
            }

            if (!q.empty())
                result += q.front();
            else
                result += '#';
        }
        return result;
    }
};