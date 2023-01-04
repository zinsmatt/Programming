class Solution {
    vector<int> res;

    void solve(int x, int n) {
        if (x <= n) {
            res.push_back(x);
        } else {
            return;
        }

        x *= 10;
        for (int i = 0; i <= 9; ++i) {
            solve(x+i, n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; ++i) {
            solve(i, n);
        }
        
        return res;
        
    }
};
