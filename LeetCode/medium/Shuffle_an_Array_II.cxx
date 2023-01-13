class Solution {
    vector<int> v;
    
public:
    Solution(vector<int>& nums) : v(nums) {

    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> temp = v;
        vector<int> res(temp.size());
        int s = temp.size();
        for (int i = 0; i < res.size(); ++i) {
            int idx = rand() % (temp.size()-i);
            res[i] = temp[idx];
            std::swap(temp[idx], temp[temp.size()-i-1]);
        }
        return res;        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
