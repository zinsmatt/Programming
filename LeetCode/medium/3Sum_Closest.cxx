class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = std::numeric_limits<int>::max();
        int best_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto x = target - nums[i];
            int l = 0, r = nums.size()-1;
            while (l < r)
            {
                if (l == i){
                  ++l;
                    continue;
                }
                if (r == i) 
                {
                    --r;
                    continue;
                }
                int d=313131;
                if (l < r)
                {
                    auto s = nums[l] + nums[r];
                    auto diff = std::abs(x - s);
                    d = diff;
                    
                    if (diff < best)
                    {
                        best = diff;
                        best_sum = s + nums[i];
                        
                    }
                    if (s > x)
                        --r;
                    else if (s < x)
                        ++l;
                    else
                        break;
                }
            }
        }
        
        return best_sum;
    }
};
