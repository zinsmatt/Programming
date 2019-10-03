class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::transform(A.begin(), A.end(), A.begin(), [](int x) { return x*x; });
        std::sort(A.begin(), A.end());
        return A;
    }
};
