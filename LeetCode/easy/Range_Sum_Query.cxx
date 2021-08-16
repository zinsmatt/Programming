class NumArray {
    vector<int> v;
public:
    NumArray(vector<int>& nums) {
        v.resize(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); ++i)
        {
            v[i] = v[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return v[right+1] - v[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
