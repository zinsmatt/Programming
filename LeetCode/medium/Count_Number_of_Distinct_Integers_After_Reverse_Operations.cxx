class Solution {
    int reverse(int x) {
        int i = 1;
        int res = 0;
        while (x) {
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        return res;
    }
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> ss;
        for (auto x : nums) {
            ss.insert(x);
            ss.insert(reverse(x));
        }
        return ss.size();
    }
};
