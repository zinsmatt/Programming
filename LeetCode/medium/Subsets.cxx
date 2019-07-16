class Solution {
public:
    std::vector<int> to_bin(int x, int n)
    {
        std::vector<int> arr(n, 0);
        int r = x;
        int i = 0;
        while (r > 0)
        {
            int q = std::floor(r/2);
            int reste = r - 2 * q;
            arr[i++] = reste;
            r = q;
        }
        std::reverse(std::begin(arr), std::end(arr));
        return arr;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        int m = std::pow(2, nums.size());
        for (int i = 0; i < m; ++i)
        {
            auto bin = to_bin(i, nums.size());
            std::vector<int> res;
            for (int k = 0; k < bin.size(); ++k)
            {
                if (bin[k] == 1)
                {
                    res.push_back(nums[k]);    
                }
            }
            out.push_back(res);
        }
        return out;
    }
};