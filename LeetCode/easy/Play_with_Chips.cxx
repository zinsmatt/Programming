class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0, odds = 0;
        for (auto c : chips)
        {
            if (c % 2 == 0)
                ++even;
            else
                ++odds;
        }
        return min(even, odds);
    }
};