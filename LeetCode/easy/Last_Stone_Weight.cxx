class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int r = stones.size() - 1;
        while (r > 0)
        {
            std::sort(stones.begin(), stones.begin() + r + 1);
            stones[r-1] = stones[r] - stones[r-1];
            --r;
        }
        return stones.front();    
    }
};