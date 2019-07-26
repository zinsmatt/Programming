class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;
        int a = 0, b = 0, aa = 0, bb = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[a])
            {
                a = i;
                b = i;
            }
            if (prices[i] > prices[b])
                b = i;
            if (prices[b] - prices[a] > m)
            {
                m = prices[b] - prices[a];
                aa = a;
                bb = b;
            }   
        }
        return m;
    }
};