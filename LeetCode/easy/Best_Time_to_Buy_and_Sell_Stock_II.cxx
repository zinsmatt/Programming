class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int best_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            best_profit = std::max(best_profit, prices[i] - min);
            min = std::min(min, prices[i]);
        }
        return best_profit;
    }
};
