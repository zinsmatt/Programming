class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        int res = 0;
        int pred = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > pred)
            {
                res += prices[i] - pred;
            }
            pred = prices[i];
        }
        return res;
    }
};