class Solution {
public:
    int trap(vector<int>& height) {
       return solve(height, 0, height.size() - 1);
    }
    
    int solve(vector<int>& height, int l, int r)
    {
        if (r - l >= 2)
        {
            int max = -1;
            int imax = -1;
            for (int i = l; i <= r; ++i)
            {
                if (height[i] > max)
                {
                    max = height[i];
                    imax = i;
                }
            }
            
            int max2 = -1;
            int imax2 = -1;
            for (int i = l; i <= r; ++i)
            {
                if (i != imax && height[i] > max2)
                {
                    max2 = height[i];
                    imax2 = i;;                    
                }
            }
            
            int d = (imax > imax2) ? 1 : -1;
            int i = imax2;
            int w = 0;
            while (i != imax)
            {
                w += max2 - height[i];
                i += d;
            }
            
            auto res_l = solve(height, l, std::min(imax, imax2));
            auto res_r = solve(height, std::max(imax, imax2), r);
            
            return w + res_l + res_r;
        }
        return 0;
    }
};