class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    int buykaro = -prices[index] + dp[index + 1][0];
                    int skip = dp[index + 1][1];
                    profit = max(buykaro, skip);
                }
                else
                {
                    int sellkaro = prices[index] + dp[index + 1][1];
                    int skip = dp[index + 1][0];
                    profit = max(sellkaro, skip);
                }

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};