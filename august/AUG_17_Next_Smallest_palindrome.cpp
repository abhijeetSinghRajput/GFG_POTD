// User function template for C++
class Solution
{
    int carry = 0;
    void add(int num[], int val, int n)
    {
        for (int i = n; i >= 0; i--)
        {
            num[i] += carry + val;
            carry = val = 0;
            carry = num[i] / 10;
            num[i] %= 10;
        }
    }

public:
    vector<int> generateNextPalindrome(int num[], int n)
    {
        // code here
        bool solved = false;
        vector<int> ans;
        for (int i = n / 2; i < n; i++)
        {
            int j = n - 1 - i;
            if (num[i] < num[j])
            {
                num[i++] = num[j--];
                while (i < n)
                {
                    num[i++] = num[j--];
                }
                solved = true;
                break;
            }
            else if (num[i] > num[j])
                break;
        }

        // agr upar ke else se break hua hai tab abhi solve krna baki hai
        if (solved)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(num[i]);
            }
            return ans;
        }
        // odd or even dono isi me cover ho jayega
        else
        {
            int mid = (n - 1) / 2;
            add(num, 1, mid);
            for (int i = mid + 1; i < n; i++)
            {
                num[i] = num[n - 1 - i];
            }
            // 9 9 9 9 9
            //     +
            // 0 0 0 9 9 carry = 1
            // 1 0 0 0 9 9 num
            // 1 0 0 0 0 0 ans
            if (carry)
                ans.push_back(carry);
            for (int i = 0; i < n; i++)
            {
                ans.push_back(num[i]);
            }
            if (carry)
                ans[n] = 1;
            return ans;
        }
    }
};