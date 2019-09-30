class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> c = heights;
        std::sort(c.begin(), c.end());
        int res = 0;
        for (int i = 0; i < c.size(); ++i)
        {
            if (c[i] != heights[i])
                ++res;
        }
        return res;
    }
};