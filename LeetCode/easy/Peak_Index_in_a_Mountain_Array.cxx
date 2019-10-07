class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return std::distance(A.begin(), std::max_element(A.begin(), A.end()));
    }
};