class Solution {
    vector<int> xors;
    void solve(vector<int>& a, int i, int x) {
        if (i < a.size()) {
            solve(a, i+1, x|a[i]);
            solve(a, i+1, x);            
        } else if (i == a.size()) {
            xors.push_back(x);   
        }
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        solve(nums, 0, 0);
        int best = *std::max_element(xors.begin(), xors.end());
        return std::count(xors.begin(), xors.end(), best);
    }
};
