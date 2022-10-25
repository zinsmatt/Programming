class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      
        unordered_map<long, int> m;
        for (auto x : nums)
            m[x] = 0;
        
        int res = 0;
        for (auto &p : m)
        {
            if (p.second == 0) {
                int r = p.first+1;
                while (m.find(r) != m.end()) {
                    m[r] = 1;
                    ++r;
                }
                
                int l = p.first-1;
                while (m.find(l) != m.end()) {
                    m[l] = 1;
                    --l;
                }
                int n = 1 + r - p.first - 1 + p.first - l - 1;
                res = max(res, n);
            }
        }
        return res;
    }
};
