class Solution {
    std::unordered_set<int> done;
    vector<int> res;

    void solve(int x, int n) {
        res.push_back(x);
        done.insert(x);
        for (int i = 0; i < n; ++i) {
            int y = (1 << i) ^ x;
            if (done.find(y) == done.end()) {
                return solve(y, n);
            }
        }       
    }
    
public:
    vector<int> circularPermutation(int n, int start) {
        solve(start, n);
        return res;
        
    }
};
