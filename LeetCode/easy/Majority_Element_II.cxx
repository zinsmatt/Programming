class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> m;
        for (auto x : nums) {
            if (m.find(x) == m.end())
                m[x] = 1;
            else
                ++m[x];
        }
        int majority = nums.size() / 2;
        for (auto it : m) {
            if (it.second > majority)
                return it.first;
        }
        return 0;
    }
};
