class Solution {
public:
    int maxArea(vector<int>& height) {
        int res_max = 0;
        int a = 0, b = height.size() - 1;
        
        while (a < b)
        {
            int v = (b - a) * std::min(height[a], height[b]);
            if (v > res_max)
                res_max = v;
            if (height[a] < height[b])
                ++a;
            else
                --b;
        }
        return res_max;
    }
};