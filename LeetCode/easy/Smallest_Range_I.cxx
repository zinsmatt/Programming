class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        auto min = *min_element(A.begin(), A.end());
        auto max = *max_element(A.begin(), A.end());
        return std::max(0, (max - K) - (min + K));
    }
};