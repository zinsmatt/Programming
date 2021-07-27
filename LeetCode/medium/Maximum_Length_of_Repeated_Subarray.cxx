class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        std::vector<std::vector<int>> g(m+1, vector<int>(n+1, 0));
        
        for (int i = m-1; i >= 0; --i)
        {
            for (int j = n-1; j >= 0; --j)
            {
                if (nums1[i] == nums2[j])
                {
                    g[i][j] = g[i+1][j+1] + 1;
                }
            }
        }
        int res = 0;
        for (auto& v : g)
        {
            for (auto x : v)
            {
                res = std::max(res, x);
            }
        }
        return res;      
    }
};
