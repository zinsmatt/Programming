class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        
        for (int i = 0; i < pow(2, nums.size()); ++i)
        {
            vector<int> tmp;
            int t = i;
            int k = 0;

            while (t > 0)
            {
                if (t % 2 == 1)
                    tmp.push_back(nums[k]);
                t /= 2;
                ++k;
            }
            std::sort(tmp.begin(), tmp.end());
            res.insert(tmp);
        }
        vector<vector<int>> resres;
        for (auto& v : res)
             resres.push_back(std::move(v));
        return resres;
    }
};