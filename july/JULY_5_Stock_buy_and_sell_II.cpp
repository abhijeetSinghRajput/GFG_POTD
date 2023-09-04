class Solution
{
public:
    int stockBuyAndSell(int n, vector<int> &prices)
    {
        // code here
        long long profit, buy;
        profit = 0;
        buy = prices[0];
        for (int current = 1; current < n - 1; current++)
        {
            int pre = current - 1;
            int post = current + 1;
            // when to sell
            if (prices[current] > prices[pre] && prices[current] >= prices[post])
            {
                profit += prices[current] - buy;
                buy = 0;
            }
            // when to buy
            if (prices[current] <= prices[pre] && prices[current] < prices[post])
            {
                buy = prices[current];
            }
        }
        // check if there any stock remains if so sel
        if (buy)
        {
            profit += prices[n - 1] - buy;
        }
        return (profit < 0) ? 0 : profit;
    }
};