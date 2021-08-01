class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        
        vector<int> max_left(height.size(), 0);
        vector<int> max_right(height.size(), 0);
        max_left[0] = height[0];
        max_right[height.size()-1] = height.back();
        
        for (int i = 1; i < height.size(); ++i)
        {
            max_left[i] = std::max(max_left[i-1], height[i]);
        }
        
        for (int i = height.size()-2; i >= 0; --i)
        {
            max_right[i] = std::max(max_right[i+1], height[i]);
        }
        
        int res = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            res += std::max(0, std::min(max_left[i], max_right[i])-height[i]);
        }
        return res;
        
    }
};
