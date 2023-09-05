class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        // poping minus
        bool minus = false;
        if (s1[0] == '-' && s2[0] != '-')
        {
            s1.erase(s1.begin());
            minus = true;
        }
        if (s1[0] != '-' && s2[0] == '-')
        {
            s2.erase(s2.begin());
            minus = true;
        }
        if (s1[0] == '-' && s2[0] == '-')
        {
            s1.erase(s1.begin());
            s2.erase(s2.begin());
        }

        vector<int> product(s1.size() + s2.size());
        for (int i = s1.size() - 1; i >= 0; i--)
        {
            int x = s1[i] - '0';
            for (int j = s2.size() - 1; j >= 0; j--)
            {
                product[i + j + 1] += x * (s2[j] - '0');
                product[i + j] += product[i + j + 1] / 10;
                product[i + j + 1] %= 10;
            }
        }

        int i = 0;
        while (i < product.size() && product[i] == 0)
            i++;

        string result;
        if (minus)
            result.push_back('-');

        while (i < product.size())
        {
            result.push_back(product[i] + '0');
            i++;
        }

        return result;
    }
};