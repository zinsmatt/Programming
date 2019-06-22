class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::set<std::vector<int>> valid;
        std::vector<std::vector<int>> res;
        if (nums.size() < 3)
            return res;
        std::sort(std::begin(nums), std::end(nums));
        int pred = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == pred)
                continue;
            pred = nums[i];
            int target = -nums[i];
            int a = 0;
            int b = nums.size() - 1;
            while (a < b)
            {
                if (a == i) ++a;
                if (b == i) --b;
                if (a >= b) break;
                if (nums[a] + nums[b] == target)
                {
                    std::vector<int> triplet = {nums[a], nums[b], -target};
                    std::sort(std::begin(triplet), std::end(triplet));
                    valid.insert(triplet);
                    a++;
                    b--;
                }
                else if (nums[a] + nums[b] < target)
                    ++a;
                else
                    --b;
            }
        }
        for (auto const& t : valid)
        {
            res.emplace_back(t);
        }
        return res;
    }
};