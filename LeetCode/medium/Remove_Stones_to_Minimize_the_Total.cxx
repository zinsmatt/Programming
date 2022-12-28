class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int res = std::accumulate(piles.begin(), piles.end(), 0);
        std::make_heap(piles.begin(), piles.end());
        for (int i = 0; i < k; ++i) {
            auto m = piles.front();
            int nouv =  std::floor(static_cast<double>(m)/2);
            res -= nouv;
            pop_heap(piles.begin(), piles.end());
            piles.pop_back();
            
            piles.push_back(m-nouv);
            push_heap(piles.begin(), piles.end());
        }
        return res;
    }
};
