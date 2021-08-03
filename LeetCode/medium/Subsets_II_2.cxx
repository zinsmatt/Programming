class Solution {
    
    vector<int> bin(int x, int n)
    {
        vector<int> res;
        while (x > 0)
        {
            res.push_back(x%2);
            x /= 2;
        }
        while (res.size() < n)
        {
            res.push_back(0);
        }
        return res;
    }
        
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        unordered_map<string, int> used;
        for (int i = 0; i < std::pow(2, nums.size()); ++i)
        {
            vector<int> s;
            auto select = bin(i, nums.size());
            // for (auto x : select) cout << x << " ";
            // cout << "\n";
            string h;
            for (int j = 0; j < select.size(); ++j)
            {
                if (select[j])
                {
                    s.push_back(nums[j]);
                    h += std::to_string(nums[j]);
                }
            }
            if (used.find(h) == used.end())
            {
                res.push_back(s);
                used[h] = 1;                
            }
        }
        return res;
    }
};



