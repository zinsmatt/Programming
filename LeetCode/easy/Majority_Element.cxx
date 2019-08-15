class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (auto k : nums)
        {
            if (m.find(k) != m.end())
            {
                m[k] += 1;
            }
            else
            {
                m[k] = 1;
            }
            if (m[k] * 2 > nums.size())
                return k;
        }
        return 0;
    }
};