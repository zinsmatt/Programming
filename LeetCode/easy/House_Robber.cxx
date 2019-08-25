class Solution {
public:
    int rob(vector<int>& nums) {
        int ci = 0;
        int di = 0;
        for (auto k : nums)
        {
            auto new_ci = std::max(ci, di + k);
            auto new_di = std::max(ci, di);
            ci = new_ci;
            di = new_di;
        }
        return std::max(ci, di);        
    }
};