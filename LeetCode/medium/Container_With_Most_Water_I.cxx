class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // We start from the largest horizontal distance,
        // then always move the smallest side because
        // it might improve the result, moving the heightest one would 
        // not change anything since the water area is limite by the smallest side

        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r)
        {
            res = std::max(res, (r-l) * std::min(height[l], height[r]));
            if (height[l] < height[r])
                ++l;
            else
                --r;
        }
        return res;
        
    }
};
