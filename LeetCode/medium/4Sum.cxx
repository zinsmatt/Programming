class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<long long> nums_l;
        for (auto x : nums)
            nums_l.push_back(x);
        std::vector<std::vector<int>> res;
        std::sort(nums_l.begin(), nums_l.end());
        for (int a = 0; a < nums_l.size(); ++a)
        {
            if (a > 0 && nums_l[a] == nums_l[a-1])
                    continue;
            for (int b = a+1; b < nums_l.size(); ++b)
            {
                if (b > a+1 && nums_l[b] == nums_l[b-1])
                    continue;
                
                int l = b+1, r = nums.size()-1;
                while (l < r)
                {
                    
                    if (l == a || l == b)
                    {
                        ++l;
                        continue;
                    }
                    if (r == a || r == b)
                    {
                        --r;
                        continue;
                    }
                    
                    auto s = nums_l[a] + nums_l[b] + nums_l[l] + nums_l[r];
                    if (s < target)
                    {
                        l++;
                    } else if (s > target)
                    {
                        --r;
                    }
                    else
                    {
                        
                        res.push_back({(int)nums_l[a], (int)nums_l[b], (int)nums_l[l], (int)nums_l[r]});    
                        auto r0 = r;
                        while (r>0 and nums_l[r] == nums_l[r0]) --r;
                        auto l0 = l;
                        while (l<nums.size() and nums_l[l] == nums_l[l0]) ++l;
                    }
                }
            }
        }
        return res;
        
    }
};
