class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        cin.tie(nullptr)->sync_with_stdio(false);
        int mn1 = prices[0];
        int sum = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            sum = max(sum, prices[i] - mn1);
            mn1 = min(mn1, prices[i]);
        }
        return sum;
    }
};