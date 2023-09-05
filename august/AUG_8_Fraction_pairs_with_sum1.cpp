// User function Template for C++
class Solution
{
    int getGCD(int x, int y)
    {
        if (x % y == 0)
            return y;
        return getGCD(y % x, x);
    }

public:
    void print(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    // hash class

    int countFractions(int n, int numerator[], int denominator[])
    {
        // STEP 1 (SIMPLIFY)
        //  simplify like 4/8 = 1/2; 8/12 = 2/3;
        for (int i = 0; i < n; i++)
        {
            int gcd = getGCD(numerator[i], denominator[i]);
            numerator[i] /= gcd;
            denominator[i] /= gcd;
        }
        // print(numerator,n);
        // print(denominator,n);

        // NEXT TO DO

        map<pair<int, int>, int> map;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int n = numerator[i], d = denominator[i];
            // if {2:3} then need {1:3} more to be one
            int needToBeOne = d - n;
            pair<int, int> p = {needToBeOne, d};
            if (map.find(p) != map.end())
                ans += map[p];

            map[{n, d}]++;
        }
        return ans;
    }
};