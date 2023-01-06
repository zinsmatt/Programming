class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (auto c : costs) {
            if (c <= coins) {
                res++;
                coins -= c;
            }
            if (c == 0)
                break;
        }
        return res;
    }
}
