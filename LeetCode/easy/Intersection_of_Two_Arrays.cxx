class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, bool> mapp;
        for (auto k : nums1)
        {
            if (mapp.find(k) == mapp.end())
            {
                mapp[k] = true;
            }
        }
        
        vector<int> res;
        for (auto k : nums2)
        {
            if (mapp.find(k) != mapp.end() && mapp[k])
            {
                res.push_back(k);
                mapp[k] = false;
            }
        }
        return res;        
    }
};